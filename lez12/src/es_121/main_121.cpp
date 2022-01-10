#include <iostream>
#include <fstream>

#include <TH1F.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TFitResult.h>

using namespace std;

int main(int argc , char * argv[]) {
	ifstream data;
	data.open ("/home/nicobigio01/repos/es_lab2/lez12/res/dati.txt", ios::in) ;
	
	double data_arr [10000];


	int i {0};
	while (true) {
		data >> data_arr[i];
		++i;
		if (data.eof () == true) break;
	}

	double x_low , x_high;
	for (int k = 0 ; k < 10000 ; ++k) {
		if (data_arr[k] < x_low) {
			x_low = data_arr[k];
		}
		if (data_arr[k] > x_high) {
			x_high = data_arr[k];
		}
	}

	TH1F data_hist ("data_hist" , "Data Histogram" , 50 , x_low , x_high);

	for (int k = 0 ; k < 10000 ; ++k) {
		data_hist.Fill(data_arr[k]);
	}

	double p0 , p1 , p2 , p3 , p4;

	TF1 backg ("backg" , "expo(0)" , x_low , x_high);
	TF1 gauss ("gauss" , "gaus(0)" , x_low , x_high);
	TF1 model ("model" , "expo(0) + gaus(2)" , x_low , x_high);

	backg.SetParameter(0 , p0);
	backg.SetParameter(1 , p1);
	gauss.SetParameter(0 , p2);
	gauss.SetParameter(1 , p3);
	gauss.SetParameter(2 , p4);

	data_hist.Fit("backg" , "Q" , "" , x_low , 4.);
	data_hist.Fit("gauss" , "Q" , "" , 7. , 14.);

	model.SetParameter(0 , backg.GetParameter(0));
	model.SetParameter(1 , backg.GetParameter(1));
	model.SetParameter(2 , gauss.GetParameter(0));
	model.SetParameter(3 , gauss.GetParameter(1));
	model.SetParameter(4 , gauss.GetParameter(2));

	TFitResultPtr fit_result = data_hist.Fit("model" , "S");

	if (fit_result->IsValid() == true) {
		cout << "FIT OK" << endl;
	}

	TCanvas c1;
	data_hist.Draw();
	c1.Print("/home/nicobigio01/repos/es_lab2/lez12/misc_output/es_121.png");

	return 0;
}