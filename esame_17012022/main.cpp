//c++ -o main main.cpp lib.cc `root-config --glibs --cflags`
//Nicolas Bigiotti - 865437
#include <iostream>
#include <vector>
#include <cmath>

#include <TH1F.h>
#include <TCanvas.h>

#include "lib.h"

using namespace std;

TH1F fill_hist (vector<double> & data , const char * name);

int main () {

    //Parte 1 - Generazione punti secondo pdf triangolare
    int n_events = 1000;
    vector<double> points;

    //Generiamo <n_events> punti distribuiti secondo una pdf triangolare
    for(int i = 0 ; i < n_events ; ++i) {
        points.push_back(triangle_tac(0. , 3.));
    }

    //Riempiamo L'istogramma con i punti generati
    TH1F hist = fill_hist(points , "std_dev_hist");

    //Calcolo e stampa di media, deviazione standard e istogramma
    cout << "\tmedia del campione:" << mean (points) << endl;
    cout << "\tdeviazione standard del campione:" << std_dev_bessel (points , mean (points)) << endl;

    TCanvas c1;
    hist.Draw();
    c1.Print("plot.png");

    //Parte 2 - Toy experiments
    int n_toy {10000} , toy_events {100};
    vector<double> toy_mean , toy_std_dev;

    points.clear();    

    //Eseguiamo un numero <n_toy> di toy experiments,
    //conservando i valori di media e varianza associati
    //ad ogni campione
    for (int i {0} ; i < n_toy ; ++i) {
        for(int k {0} ; k < toy_events ; ++k) {
            points.push_back(triangle_tac(0. , 3.));
        }
        toy_mean.push_back(mean(points));
        toy_std_dev.push_back(std_dev_bessel(points , toy_mean.back()));
        points.clear();
    }
    
    //Creiamo e stampiamo gli istogrammi relativi ai risultati dei toy experiments
    TH1F mean_hist = fill_hist(toy_mean , "mean_hist");

    TCanvas c2;
    mean_hist.Draw();
    c2.Print("mean.png" , "png"); 


    TH1F std_dev_hist = fill_hist(toy_mean , "std_dev_hist");
    for (vector<double>::iterator it = toy_std_dev.begin() ; it != toy_std_dev.end() ; ++it) {
        std_dev_hist.Fill(*it);
    }

    TCanvas c3;
    std_dev_hist.Draw();
    c3.Print("std.png" , "png");
    
    return 0;
}

//Questa funzione crea un istogramma con identificatore di root `name`
//e lo riempe con i dati contenuti nel campione `data`,
//la scelta dei limiti dell'istogramma e del numero di bin è automatica
TH1F fill_hist (vector<double> & data , const char * name) {
    double percent_25 , percent_75 , bin_wdth;
    sort(data.begin() , data.end());

    //Utilizzo la regola di Freedman-Diaconis per calcolare 
    //automaticamente il numero di bin necessari
    percent_25 = data.at( round(static_cast<double> (data.size()) * 0.25) - 1);
    percent_75 = data.at( round(static_cast<double> (data.size()) * 0.75) - 1);
    bin_wdth = 2 * (percent_75 - percent_25) / cbrt(data.size());
    TH1F tmp_hist (
        name ,
        name ,
        round((data.back() - data.front()) / bin_wdth) ,
        data.front() ,
        data.back()
    );
    for(vector<double>::iterator it = data.begin() ; it != data.end() ; ++it)
        tmp_hist.Fill(*it);

    //cout << "bin_width: " << bin_wdth << "\tfirst: " << data.front() << "\tlast: " << data.back() << endl;
    return tmp_hist;
}
