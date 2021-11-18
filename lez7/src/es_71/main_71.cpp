#include <iostream>
#include <TH1F.h>
#include <TCanvas.h>
#include "../../include/pdf.h"


int main(int argc , char * argv[]) {
	pdf pdf1 ;

	
	TH1F ist ("ist" , "Esponenziale" , 100 , 0 , 10);

	for(int i = 0 ; i < 1000000 ; ++i) {
		double temp = pdf1.generate_exp(5.0);
		//std::cout << temp << std::endl;
		ist.Fill(temp);
	}

	TCanvas c1 ;
	ist.Draw () ;
	c1.Print ("misc_output/es_71.png", "png") ;

	return 0;
}