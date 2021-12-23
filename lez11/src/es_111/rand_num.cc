#include <cstdlib>
#include "rand_num.h"

    int rand_num::set_max(int max) {
        max_num = max;
        return 0;
    }

    int rand_num::set_min(int min) {
        min_num = min;
        return 0;
    }

    int rand_num::set_seed(int seed) {
        srand(seed);
        return 0;
    }

    double rand_num::get_rnd() {
        double num = min_num + (max_num - min_num) * (rand() / static_cast<float> (RAND_MAX));
        return num;
    }

