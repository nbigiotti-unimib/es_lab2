#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

#include <TH2F.h>
#include <TCanvas.h>

#include "matrici.h"

double gauss_tac(double sigma , double x_min , double x_max , double y_max);
double cov (std::vector<vettore2> vec);

int main () {
    std::vector<vettore2> gauss2d;
    std::vector<vettore2> gauss2d_rot;

    for (int i = 0 ; i < 1000 ; ++i) {
        vettore2 tmp (
            gauss_tac(3. , -100. , 100. , 100.) ,
            gauss_tac(1. , -100. , 100. , 100.)
        );
        std::cout << gauss_tac(3. , -100. , 100. , 100.) << std::endl;
        gauss2d.push_back(tmp);
    }

    TH2F gauss_hist ("gauss_hist" , "Istogramma" , 50 , -10. , 10. , 50 , -10. , 10.);
    TH2F gauss_hist_rot ("gauss_hist_rot" , "Istogramma Ruotato" , 50 , -10. , 10. , 50 , -10. , 10.);
    //TH1F gauss_hist ("gauss_hist" , "Istogramma" , 50 , -10. , 10.);
    
    for (std::vector<vettore2>::iterator it = gauss2d.begin() ; it != gauss2d.end() ; ++it) {
        gauss_hist.Fill(it->elem(0) , it->elem(1));
        //gauss_hist.Fill(it->elem(0));
    }

    matrice2x2 rot (3.14 / 6.);
    
    for (std::vector<vettore2>::iterator it = gauss2d.begin() ; it != gauss2d.end() ; ++it) {
        vettore2 res = rot * *it;
        gauss2d_rot.push_back(res);
        gauss_hist_rot.Fill(res.elem(0) , res.elem(1));
    }
    
    std::cout << "cov 1: " << cov (gauss2d) << std::endl;
    std::cout << "cov rot: " << cov (gauss2d_rot) << std::endl;

    TCanvas c1;
    gauss_hist.SetMarkerColor(kRed);
    gauss_hist.Draw();
    gauss_hist.SetMarkerColor(kBlue);
    gauss_hist_rot.Draw("same");
    c1.Print("ex.png");    

    return 0;
}



double gauss_tac(double sigma , double x_min , double x_max , double y_max) {
    double x;
    double y;    
    do {
        x = x_min + (rand() / static_cast<double> (RAND_MAX)) * (x_max - x_min);
        y = (rand() / static_cast<double> (RAND_MAX)) * y_max;
        //std::cout << "\tx: " << x << "\ty: " << y << std::endl;
    } while ( y > ( exp(- 0.5 * pow( (x / sigma) , 2) ) ) / ( sqrt(6.283) * sigma ) );

    return x;
}

double cov (std::vector<vettore2> vec) {
    double a {0} , b {0} , c {0} , cov {0};

    for (std::vector<vettore2>::iterator it = vec.begin() ; it != vec.end() ; ++it) {
        a += it->elem(0) * it->elem(1);
        b += it->elem(0);
        c += it->elem(1);
    }
    cov = a / vec.size() - (b * c) / (vec.size() * vec.size());  
    return cov;  
}