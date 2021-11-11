#include <iostream>

int main(int argc , char * argv[]) {
	double x[4];
	double r = 0.618;
	double precision = 0.001;
	double y[4];

	x[0] = -10.0;
	x[3] = 10.0;
	x[2] = x[0] + r * (x[3] - x[0]);
	x[1] = x[0] + (1 - r) * (x[3] - x[0]);
	while((x[3] - x[0]) > precision) {
		for (int i = 0 ; i < 4 ; ++i) {
			y[i] = x[i] * x[i] + 7.3 * x[i] + 4;
		}

		if(((y[1] - y[0]) * (y[2] - y[1])) < 0 ) {
			x[3] = x[2];
			x[2] = x[1];
			x[1] = x[0] + (1 - r) * (x[3] - x[0]);
		} else {
			//elimina primo intervallo
			x[0] = x[1];
			x[1] = x[2];
			x[2] = x[0] + r * (x[3] - x[0]);
		}

	}
	
	std::cout << "Il minimo è compreso fra " << x[0] << " e " << x[3] << std::endl;
	return 0;
}