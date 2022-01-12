#include <cstdlib>

static double rand_range(double min , double max);
static double get_max(double pdf(double) , double x_min , double x_max , double precision);

double pdf_tac (double pdf(double) , double x_min , double x_max) {
    double y_max {pdf(get_max(pdf , x_min , x_max , 0.0001))};
    double x , y;
    do {
        x = rand_range(x_min , x_max);
        y = rand_range(0 , y_max);
    } while (y > pdf(x));
        
    return x;
}

static double get_max(double pdf(double) , double x_min , double x_max , double precision) {
    double r {0.618};
    double points[] = {
        x_min ,
        x_min + (1 - r) * (x_max -x_min) ,
        x_min + r * (x_max -x_min) ,
        x_max
    };

    while ((points[3] - points[0] > precision)) {
        if (pdf(points[1]) < pdf(points[2])) {
            //0 1   2   3
            //1 2   n   3
            points[0] = points[1];
            points[1] = points[2];
            points[2] = points[0] + r * (points[3] - points[0]);
        } else {
            //0 1   2 __ 3
            //0 n   1   2
            points[3] = points[2];
            points[2] = points[1];
            points[1] = points[0] + (1 - r) * (points[3] - points[0]);
        }
    }
    return (points[3] + points[0]) / 2;
}

static double rand_range(double min , double max) {  
    return min + (rand() / static_cast<double> (RAND_MAX)) * (max - min);
}