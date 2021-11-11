#include <iostream>
#include <cmath>

int main(int argc , char * argv[]) {
	double interv[3] = {0 , 2 , 4};
	double min = -1;
	double precision = 0.00001;

	while (interv[2] - interv[0] > precision) {
		if (cos(interv[0]) * cos(interv[1]) < 0) {
			interv[2] = interv[1];
			interv[1] = (interv[0] + interv[2]) / 2;
		} else {
			interv[0] = interv[1];
			interv[1] = (interv[0] + interv[2]) / 2;
		}
	}
	std::cout << "Il minimo è compreso fra: " << interv[0] << " e " << interv[2] << std::endl;
	return 0;
}