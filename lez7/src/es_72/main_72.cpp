#include <iostream>
#include "../../include/pdf.h"
#include <TH1F.h>
#include <TCanvas.h>

int main(int argc , char * argv[]) {
	double t_0  = 1.0, t_M = 10.0;
	int N = 1000000;

	pdf pdf1;

	TH1F ist ("ist" , "Esponenziale" , 75 , 0 , 30);
	double t_int = 0;
	int count = 0;
	for(int i = 0 ; i < N ; ++i) {
		t_int = 0;
		count = 0;
		while (t_int < t_M) {
			t_int += pdf1.generate_exp(t_0);
			++count;
		}
		ist.Fill(count);		
	}

	TCanvas c1 ;
	ist.Draw () ;
	c1.Print ("misc_output/es_72.png", "png") ;

	return 0;
}