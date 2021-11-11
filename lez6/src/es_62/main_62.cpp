#include <iostream>
#include <cmath>

int zeroes(double inf , double sup);

int main(int argc , char * argv[]) {
	zeroes(0,4);
	return 0;
}

int zeroes(double inf , double sup) {
	double precision = 0.001;
	if ((sup - inf) < precision) {
		std::cout << "Il minimo è compreso fra: " << inf << " e " << sup << std::endl;
		return 0;
	}
	if (cos(inf) * cos((inf + sup) / 2.0) < 0) {
		sup = (inf + sup) / 2.0;
	} else {
		inf = (inf + sup) / 2.0;
	}	
	zeroes(inf , sup);	
	return 0;
}