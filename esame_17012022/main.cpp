//c++ -o main main.cpp lib.cc `root-config --glibs --cflags`
//Nicolas Bigiotti - 865437
#include <iostream>
#include <vector>
#include <cmath>

#include <TH1F.h>
#include <TCanvas.h>

#include "lib.h"

using namespace std;

int main () {

    //Parte 1 - Generazione punti secondo pdf triangolare
    int n_events = 1000;
    vector<double> points;

    //Generiamo `n_events` punti distribuiti secondo una pdf triangolare
    for(int i = 0 ; i < n_events ; ++i) {
        points.push_back(triangle_tac(0. , 3.));
    }

    //Riempiamo L'istogramma con i punti generati
    TH1F hist ("hist" , "Istogramma misure" , 13 , 0. , 3.);
    for (vector<double>::iterator it = points.begin() ; it != points.end() ; ++it) {
        hist.Fill(*it);
    }

    //Calcolo e stampa di media, deviazione standard e istogramma
    cout << "\tmedia del campione:" << mean(points) << endl;
    cout << "\tdeviazione standard del campione:" << std_dev_bessel(points , mean (points)) << endl;

    TCanvas c1;
    hist.Draw();
    c1.Print("plot.png");

    //Parte 2 - Toy experiments
    int n_toy {10000} , toy_events {100};
    double mean_max{-100.} , mean_min{100.};
    double std_dev_max{-100.} , std_dev_min{100.};
    vector<double> toy_mean , toy_std_dev;

    points.clear();    

    //Eseguiamo un numero `n_toy` di toy experiments,
    //conservando i valori di media e varianza associati
    //ad ogni campione
    
    for (int i {0} ; i < n_toy ; ++i) {
        for(int k {0} ; k < toy_events ; ++k) {
            points.push_back(triangle_tac(0. , 3.));
        }
        
        double tmp_mean {mean(points)};
        double tmp_std_dev {std_dev_bessel(points , tmp_mean)};
        toy_mean.push_back(tmp_mean);
        toy_std_dev.push_back(tmp_std_dev);
        if (tmp_mean > mean_max)
            mean_max = tmp_mean;
        if (tmp_mean < mean_min)
            mean_min = tmp_mean;
        if (tmp_std_dev > std_dev_max)
            mean_max = tmp_std_dev;
        if (tmp_std_dev < std_dev_min)
            std_dev_min = tmp_std_dev;
        points.clear();
    }
    
    //Creiamo e stampiamo gli istogrammi relativi ai risultati dei toy experiments
    TH1F mean_hist ("mean_hist" , "Istogramma media" , 30 , mean_min , mean_max);
    TH1F std_dev_hist ("std_dev_hist" , "Istogramma deviazione standard" , 30 , std_dev_min , std_dev_max);
    for (int i = 0 ; i < n_toy ; ++i) {
        mean_hist.Fill(toy_mean[i]);
        std_dev_hist.Fill(toy_std_dev[i]);
    }

    TCanvas c2;
    mean_hist.Draw();
    c2.Print("mean.png" , "png"); 

    TCanvas c3;
    std_dev_hist.Draw();
    c3.Print("std.png" , "png");
    
    return 0;
}