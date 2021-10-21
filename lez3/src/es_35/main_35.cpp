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

int fillHist (TH1F * hist , double * data , int N);
int getData (std::string filename , double * data , int N , double min_val , double max_val);

int main (int argc , char * argv[]) {
    int N;
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << "N" << std::endl;
        return 1;
    }
    std::stringstream tmp_str;
    tmp_str << argv[1];
    tmp_str >> N;

    std::string filename1 ("res/eventi_unif.txt");
    std::string filename2 ("res/eventi_gauss.txt");
    double *data1 , *data2 , max_val1 , min_val1 , max_val2 , min_val2;

    data1 = new double[N];
    data2 = new double[N];

    getData(filename1 , data1 , N , min_val1 , max_val1);
    TH1F h1 ("h1" , "Istogramma es. 3.5 - 1" , N / 5 , min_val1 , max_val1);
    fillHist(&h1 , data1 ,N);
    
    getData(filename2 , data2 , N , min_val2 , max_val2);
    TH1F h2 ("h2" , "Istogramma es. 3.5 - 2" , N / 5 , min_val2 , max_val2);
    fillHist(&h2 , data2 ,N);

    TApplication myApp ("myApp" , &argc , argv);
        TCanvas c1;
        h1.Draw();
        h2.Draw();
        c1.Print("misc_output/es35_h1.png" , "png");
    myApp.Run();

    return 0;
}




int getData (std::string filename , double * data , int N , double min_val , double max_val) {
        std::ifstream input_file;
    input_file.open (filename , std::ios::in);
    if (input_file.is_open() == false) {
        std::cout << "ERROR while opening \"" << filename << "\": " << strerror (errno)  << std::endl;
        return 1;
    }

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

    input_file.close();
    return 0;
}

int fillHist (TH1F * hist , double * data , int N) {
    std::cout << data[0];
    for (int i = 0 ; i < N ; ++i) {
        hist->Fill(data[i]);
    }
    return 0;
}