#include <vector>
#include <cmath>

#include "lib.h"

#include <TH1F.h>
#include <TCanvas.h>

using namespace std;

double pdf (double x);

int main () {
    int n_events = 10000;
    vector<double> data;

    for(int i = 0 ; i < n_events ; ++i) {
        data.push_back(pdf_tac(pdf , 0 , 3.14));
    }

    TH1F hist ("hist" , "Istogramma" , 50 , 0. , 3.14);

    for (vector<double>::iterator it = data.begin() ; it != data.end() ; ++it) {
        hist.Fill(*it);
    }

    TCanvas c1;
    hist.Draw();
    c1.Print("plot.png");

    return 0;
}


double pdf (double x) {
    return 0.5 * sin (x);
}