#include <iostream>
#include "../../include/pdf.h"
#include <TH1F.h>
#include <TCanvas.h>

int main(int argc , char * argv[]) {
	double lambda = 1.0;
	int N = 1000000;
	
	pdf pdf1;
	TH1F ist ("ist" , "Poissoniana" , 1000 , 0 , lambda * 10);

	for(int i = 0 ; i < N ; ++i) {
		ist.Fill(pdf1.generate_poisson(lambda));		
	}

	TCanvas c1 ;
	ist.Draw () ;
	c1.Print ("misc_output/es_73_1.png", "png") ;

	return 0;
}