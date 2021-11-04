#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sstream>

int main (int argc , char * argv[]) {
    int N;
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << "N" << std::endl;
        return 1;
    }
    std::stringstream tmp_str;
    tmp_str << argv[1];
    tmp_str >> N;

    

    std::string filename ("res/eventi_gauss.txt");
    std::ifstream input_file;
    input_file.open (filename , std::ios::in);
    if (input_file.is_open() == false) {
        std::cout << "ERROR: " << strerror (errno)  << std::endl;
        return 1;
    }

    
    double * data = new double[N];

    double min_val = -1 , max_val = -1;

    for (int i = 0 ; i < N ; ++i) {
        input_file >> data[i];

                if (i == 0) {
            min_val = data[i];
            max_val = data[i];
        } else if (data[i] > max_val) {
            max_val = data[i];
        } else if (data[i] < min_val) {
            min_val = data[i];
        }
    }

    TH1F h1 ("h1" , "Istogramma esercizio 3.4" , N / 5 , min_val , max_val);
    for (int i = 0 ; i < N ; ++i) {
        h1.Fill(data[i]);
    }

    TApplication myApp ("myApp" , &argc , argv);
        TCanvas c1;
        h1.Draw();
        c1.Print("misc_output/es34_h1.png" , "png");
    myApp.Run();

    return 0;
}