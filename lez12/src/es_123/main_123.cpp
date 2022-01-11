#include <iostream>
#include <cmath>
#include <fstream>

#include <TH1F.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TFitResult.h>

using namespace std;

int main(int argc , char * argv[]) {
	int n_events = 100;
	double x_low {1000.} , x_high {-1000.};
	double gauss_arr [n_events];
	ifstream data;
	data.open("/home/nicobigio01/repos/es_lab2/lez12/res/dati2.txt" , ios::in);

	for (int i = 0 ; i < n_events ; ++i) {
		data >> gauss_arr[i];
		if (gauss_arr[i] < x_low) {
			x_low = gauss_arr[i];
		}
		if (gauss_arr[i] > x_high) {
			x_high = gauss_arr[i];
		}
	}

	TH1F gauss_hist ("gauss_hist" , "Gauss Sample Histogram" , 50 , x_low , x_high);

	for (int i = 0 ; i < n_events ; ++i) {
		gauss_hist.Fill(gauss_arr[i]);
	}

	double p0 , p1 , p2;
	TF1 gauss_funct ("gauss" , "gaus(0)" , x_low , x_high);
	gauss_funct.SetParameter(0 ,p0);
	gauss_funct.SetParameter(1 ,p1);
	gauss_funct.SetParameter(2 ,p2);

	TFitResultPtr fit_res = gauss_hist.Fit("gauss" , "S" , "" , x_low , x_high);
	cout << endl << endl;
	TFitResultPtr fit_res_l = gauss_hist.Fit("gauss" , "SL+" , "" , x_low , x_high);

	TCanvas c1;
	gauss_hist.Draw();
	c1.Print("/home/nicobigio01/repos/es_lab2/lez12/misc_output/es_123.png");

	return 0;
}