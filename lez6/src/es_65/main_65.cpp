#include <iostream>

int minimo (double x_0 , double x_1 , double x_2 , double x_3);


int main(int argc , char * argv[]) {
	minimo(-10 , -2.36 , 2.36 , 10);
	return 0;
}

int minimo (double x_0 , double x_1 , double x_2 , double x_3) {
	double precision = 0.001;
	double x[4] = {x_0 , x_1 , x_2 , x_3};
	double y[4];
	double r = 0.618;
	


	if ((x[3] - x[0]) < precision) {
		std::cout << "Il minimo è compreso fra " << x[0] << " e " << x[3] << std::endl;
		return 0;
	}
	for (int i = 0 ; i < 4 ; ++i) {
		y[i] = x[i] * x[i] + 7.3 * x[i] + 4;
	}
	
	if(((y[1] - y[0]) * (y[2] - y[1])) < 0 ) {
		minimo(x[0] , x[0] + (1 - r) * (x[2] - x[0]) , x[1] , x[2]);
	} else {
		//elimina primo intervallo
		minimo(x[1] , x[2] , x[1] + r * (x[3] - x[1]) , x[3]);
	}
	return 0;
}