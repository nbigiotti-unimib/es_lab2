#include <iostream>
#include <vector>
#include <cmath>

#include "matrici.h"

double gauss_tac(double pdf(double) , double x_min , double x_max , double y_max);

int main () {
    std::vector<vettore2> gauss2d;

    for (int i = 0 ; i < 1000 ; ++i) {
        vettore2 tmp (
            gauss_tac(3 , -100 , 100 , ) ,
            gauss_tac(1 , -100 , 100 , )
        );
    }
    
    return 0;
}



double gauss_tac(double sigma , double x_min , double x_max , double y_max) {
    double x;
    double y;    
    do {
        x = x_min + (rand() / RAND_MAX) * (x_max - x_min);
        y = (rand() / RAND_MAX) * y_max;
    } while (y > (1 / sqrt(6.283 * sigma)) * exp(- pow(x / sigma , 2)));

    return x;
}