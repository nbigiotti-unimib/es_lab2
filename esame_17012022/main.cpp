//c++ -o main main.cpp lib.cc `root-config --glibs --cflags`
#include <iostream>
#include <vector>
#include <cmath>

#include <TH1F.h>
#include <TCanvas.h>

#include "lib.h"

using namespace std;

int main () {
    int n_events = 1000;
    vector<double> points;

    for(int i = 0 ; i < n_events ; ++i) {
        points.push_back(triangle_tac(0. , 3.));
    }

    TH1F hist ("hist" , "Istogramma" , 50 , 0. , 3.);

    for (vector<double>::iterator it = points.begin() ; it != points.end() ; ++it) {
        hist.Fill(*it);
    }

    cout << "\tmedia del campione:" << mean (points) << endl;
    cout << "\tdeviazione standard del campione:" << std_dev_bessel (points , mean (points)) << endl;

    TCanvas c1;
    hist.Draw();
    c1.Print("plot.png");

    return 0;
}