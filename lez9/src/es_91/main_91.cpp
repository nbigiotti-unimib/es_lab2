#include <iostream>
#include <vector>
#include <libLAB2/pdf.h>

int main(int argc , char * argv[]) {
	
	if (argc < 3) {
		printf("Usage: %s <t_0> <n_eventi>\n" , argv[0]);
		return 1;
	}
	
	double t_0 = atoi(argv[2]);
	int n_eventi = atoi(argv[2]);
	std::vector<double> tempi;
	pdf exp;

	for (int i = 0 ; i  < n_eventi ; ++i) {
		tempi.push_back(exp.generate_exp(t_0));
	}

	return 0;
}