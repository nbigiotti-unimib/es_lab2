#include <iostream>
#include <cmath>
#include <fstream>

#include <TH1F.h>
#include <TCanvas.h>

using namespace std;

double generate_gauss(double media , double sigma , int n_events);

int main(int argc , char * argv[]) {
	int data_n = 10000;

	double gauss_arr [data_n];

	ofstream data;

	data.open("/home/nicobigio01/repos/es_lab2/lez12/res/dati2.txt" , ios::out);
	
	for (int i = 0 ; i < data_n ; ++i) {
		data << generate_gauss(10. , 0.5 , data_n) << endl;
	}

	return 0;
}

double generate_gauss(double media , double sigma , int n_events) {
    double b = media + sqrt(3. * n_events) * sigma;
    double a = media - sqrt(3. * n_events) * sigma;
	double sum = 0;

    for (int i = 0 ; i < n_events ; ++i) {
        sum += a + (b - a) * (rand() / static_cast<float> (RAND_MAX));
    }

    return sum / n_events;
};