#include "../../include/exp.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include <stdio.h>

exp_pdf::exp_pdf(double t_0):
    __t_0 (t_0)
    {};

double exp_pdf::inv_pdf(double y) {
    double x;
    
    x = - this->__t_0 * log(1 - y);
    //printf("t_0: %f , x: %f , y: %f\n" , this->__t_0 , x , y);
    return x;
};

double exp_pdf::generate_exp() {
    double temp = rand() / static_cast<float> (RAND_MAX);
    //printf("rand: %f" , temp);
    double point = inv_pdf(temp);
    

    return point;
};