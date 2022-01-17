#include <cstdlib>

static double triangle_pdf (double x);
static double rand_range(double min , double max);

double triangle_tac (double x_min , double x_max) {
    //double y_max {pdf(get_max(pdf , x_min , x_max , 0.0001))};
    double y_max {2. / 3.};
    double x , y;
    do {
        x = rand_range(x_min , x_max);
        y = rand_range(0. , y_max);
    } while (y > triangle_pdf(x));
        
    return x;
}

static double rand_range(double min , double max) {  
    return min + (rand() / static_cast<double> (RAND_MAX)) * (max - min);
}

double triangle_pdf (double x) {
    double k {2. / 9.};

    if (x < 0 || x > 3) {
        return 0.;
    }
    return k * x;
}