#include <iostream>
#include <fstream>
#include <vector>

#include <TH1F.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TCanvas.h>

using namespace std;

TH1F fill_hist (vector<double> & data);
double likelyhood (vector<double> & x_i , double k);

double get_max(double f(vector<double> & , double) , vector<double> & params , double x_min , double x_max , double precision);

int main() {
    ifstream pois_txt;
    pois_txt.open("dati.txt" , ios::in);
    vector<double> pois_data;

    do {
        double tmp;
        pois_txt >> tmp;
        pois_data.push_back(tmp);
    } while (pois_txt.eof() == false);

    TH1F pois_hist = fill_hist(pois_data);

    double k_min {0.1} , k_max {4.} , k_step {0.001} , k;
    TGraph l_graph , l15 , l10;

    for (k = k_min ; k <= k_max ; k += k_step) {
        
        l_graph.SetPoint( 
            l_graph.GetN() ,
            k ,
            likelyhood(pois_data , k)
        );
    }
    for(int i = 0 ; i < 5 ; ++i)
        pois_data.pop_back();

    for (k = k_min ; k <= k_max ; k += k_step) {
        
        l15.SetPoint( 
            l15.GetN() ,
            k ,
            likelyhood(pois_data , k)
        );
    }

    for(int i = 0 ; i < 5 ; ++i)
        pois_data.pop_back();

    for (k = k_min ; k <= k_max ; k += k_step) {
        
        l10.SetPoint( 
            l10.GetN() ,
            k ,
            likelyhood(pois_data , k)
        );
    }

    
    cout << "k: " << get_max(likelyhood , pois_data , 0.1 , 1. , 0.0001) << endl << endl;

    TCanvas c1;
    pois_hist.Draw();
    c1.Print("hist.png" , "png");

    TCanvas c2;
    l_graph.Draw();
    c2.Print("likely.png" , "png");

    TMultiGraph mg;
    TCanvas c3;
    mg.Add(&l_graph);
    mg.Add(&l15);
    mg.Add(&l10);
    mg.Draw("AC");
    c3.Print("likely2.png" , "png");

    return 0;
}



TH1F fill_hist (vector<double> & data) {
    sort(data.begin() , data.end());
    double percent_25 , percent_75 , bin_wdth;
    percent_25 = data.at( round(static_cast<double> (data.size()) * 0.25) - 1);
    percent_75 = data.at( round(static_cast<double> (data.size()) * 0.75) - 1);
    bin_wdth = 2 * (percent_75 - percent_25) / cbrt(data.size());
    TH1F hist (
        "hist" ,
        "Histogram" ,
        round((data.back() - data.front()) / bin_wdth) ,
        data.front() ,
        data.back()
    );
    for(vector<double>::iterator it = data.begin() ; it != data.end() ; ++it)
        hist.Fill(*it);

    //cout << "bin_width: " << bin_wdth << "\tfirst: " << data.front() << "\tlast: " << data.back() << endl;
    return hist;
}

double likelyhood (vector<double> & x_i , double k) {
    double l {1.};
    for(vector<double>::iterator it = x_i.begin() ; it != x_i.end() ; ++it) {
        l *= k * exp(- k * *it);
    }
    
    return l;    
}

double get_max(double f(vector<double> & , double) , vector<double> & params , double x_min , double x_max , double precision) {
    double r {0.618};
    double points[] = {
        x_min ,
        x_min + (1 - r) * (x_max -x_min) ,
        x_min + r * (x_max -x_min) ,
        x_max
    };

    while ((points[3] - points[0] > precision)) {
        if (f(params , points[1]) < f(params , points[2])) {
            //0 1   2   3
            //1 2   n   3
            points[0] = points[1];
            points[1] = points[2];
            points[2] = points[0] + r * (points[3] - points[0]);
        } else {
            //0 1   2 __ 3
            //0 n   1   2
            points[3] = points[2];
            points[2] = points[1];
            points[1] = points[0] + (1 - r) * (points[3] - points[0]);
        }
    }
    return (points[3] + points[0]) / 2;
}