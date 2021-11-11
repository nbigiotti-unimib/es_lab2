#include <iostream>
#include <TF1.h>
#include <TCanvas.h>
#include <TMarker.h>
#include <TApplication.h>


int main(int argc , char * argv[]) {

	TApplication myApp ("myAPP" , &argc , argv);
	TF1 funct1 ("fa1", "x^2+7.3*x+4", -10, 10);
	TCanvas c1;
	funct1.Draw ();

	TMarker minimo (-3.65, -9.322, 20);
	minimo.Draw ();
	myApp.Run();
	return 0;
}