#include <iostream>
#include <cmath>

bool solve2ndDegree (double * par, double * x);

int main (int argc , char * argv[]) {
	double eq[] = {-1 , -1 , -1};
	double sol[2] = {-1 , -1};
	
	for (int i = 0 ; i < 3 ; i += 1) {
		std::cout << "Inserire il tre parametri a, b e c" << std::endl;
		std::cin >> eq[i];
	}


	if (solve2ndDegree(eq , sol)) {
		std::cout << "Soluzione x_1 = " << sol[0] << std::endl;
		std::cout << "Soluzione x_2 = " << sol[1] << std::endl;
	} else {
		std::cout << "L'equazione non ha soluzioni" << std::endl;
	}
	return 0;
}

bool solve2ndDegree (double * par, double * x) {
	double a = par[0];
	double b = par[1];
	double c = par[2];
	
	double delta = b * b - 4 * a * c;
	
	if (delta < 0)
		//delta negativo, non esistono soluzioni reali
		return false;

	x[0] = (-b + std::sqrt(delta)) / 2 * a;
	x[1] = (-b - std::sqrt(delta)) / 2 * a;

	return true;
}
