#include <iostream>
#include <cmath>

#include <TF1.h>
#include <TCanvas.h>
#include <libLAB2/pdf.h>

Double_t loglikelihood (Double_t * x, Double_t * par);

int main(int argc , char * argv[]) {
	
	TF1 f_likelihood ("f_likelihood" , loglikelihood , 1 , 1000 , 1);
	f_likelihood.SetParameter(0 , 100);

	TCanvas c1;
	f_likelihood.Draw();
	c1.Print("misc_output/es_94_2.png" , "png");

	return 0;
}

Double_t loglikelihood (Double_t * x, Double_t * par) {
  	double likelihood = 0, n_eventi = par[0];
	
	pdf esp;

	for (int i = 0 ; i  < n_eventi ; ++i) {
		double temp = esp.generate_exp(x[0]);
		likelihood += log(esp.generate_exp(temp));
		printf("DEBUG: %lf ; likelihood: %lf\n" , temp , likelihood);
	}
	if (likelihood <= 0)
		return 1.;

	return likelihood;
}