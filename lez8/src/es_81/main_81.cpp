#include <iostream>
#include <libLAB2/statistiche.h>
#include <libLAB2/rand_num.h>
#include <time.h>

int main(int argc , char * argv[]) {
	/*if(argc < 3) {
		std::cout << "Usage: " << argv[0] << " NMAX NTOYS" << std::endl;
	}*/

	rand_num r_class;
	r_class.set_seed(time(NULL));
	r_class.set_max(3);

	statistiche stat_val;
	statistiche stat_mean;

	int NMAX {100};
	int NTOYS {100};

	for (int i = 0 ; i < NTOYS ; ++i) {
		for (int k = 0 ; k < NMAX ; ++k) {
			printf("DEBUG: %f\n" , r_class.get_rnd());
			stat_val.add_value (r_class.get_rnd());
		}
		stat_mean.add_value(stat_val.get_mean());
		stat_val.reset();
	}
	std::cout << "Media: " << stat_mean.get_mean() << std::endl;

	return 0;
}