#include <iostream>
#include <vector>
#include <cmath>

#include <TF1.h>
#include <TCanvas.h>
#include <libLAB2/pdf.h>

Double_t esponenziale (Double_t * x , Double_t * param);

int main(int argc , char * argv[]) {
	
	if (argc < 2) {
		printf("Usage: %s <t_0>\n" , argv[0]);
		return 1;
	}
	
	double t_0 = atoi(argv[1]);

	TF1 esp ("funz-esp" , esponenziale , 0 , 5 * t_0 , 1);
	esp.SetParameter (0, t_0);

	TCanvas c1;
	esp.Draw();
	c1.Print("misc_output/es_93.png" , "png");

	return 0;
}

Double_t esponenziale (Double_t * x , Double_t * param) {
	double t_0 = param[0];
	if (t_0 == 0) {
		return 1.;
	}
	return (1 / t_0) * exp(-(x[0]/t_0));
}