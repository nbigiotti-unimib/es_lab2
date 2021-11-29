#include <iostream>
#include <vector>

#include <TH1F.h>
#include <TCanvas.h>
#include <libLAB2/pdf.h>


int main(int argc , char * argv[]) {
	
	if (argc < 3) {
		printf("Usage: %s <t_0> <n_eventi>\n" , argv[0]);
		return 1;
	}
	
	double t_0 = atoi(argv[1]);
	int n_eventi = atoi(argv[2]);
	std::vector<double> tempi;
	TH1F exp_ist ("exp_ist" ,"exp_ist" , 100 , 0 , 10);
	pdf exp;

	for (int i = 0 ; i  < n_eventi ; ++i) {
		double temp = exp.generate_exp(t_0);
		tempi.push_back(temp);
	}

	for (std::vector<double>::iterator it = tempi.begin() ; it < tempi.end() ; ++it) {
		exp_ist.Fill(*it);
	}

	TCanvas c1;
	exp_ist.Draw();
	c1.Print("misc_output/es_92.png" , "png");

	return 0;
}