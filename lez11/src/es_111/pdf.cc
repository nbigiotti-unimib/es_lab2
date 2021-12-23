#include "pdf.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <stdio.h>

pdf::pdf() {};

double pdf::inv_exp_pdf(double y , double t_0) {
    double x;
    
    x = - t_0 * log(1 - y);
    //printf("t_0: %f , x: %f , y: %f\n" , this->__t_0 , x , y);
    return x;
};

double pdf::generate_exp(double t_0) {
    double temp = rand() / static_cast<float> (RAND_MAX);
    //printf("rand: %f" , temp);
    double point = inv_exp_pdf(temp , t_0);
    
    return point;
};

double pdf::generate_poisson(double lambda) {
	double t_int = 0 , t_M = 1.0;
	int count = 0;
	
    while (t_int < t_M) {
		t_int += this->generate_exp(1. / lambda);
		++count;
	}
    
    return count;
}; //l = N/t_i  

double pdf::generate_gauss(double media , double sigma , int n_events) {
    double b = media + sqrt(3. * n_events) * sigma;
    double a = media - sqrt(3. * n_events) * sigma;    
    
    //printf("DEBUG: %lf , %lf\n" , a , b);
    

    double sum = 0;

    for (int i = 0 ; i < n_events ; ++i) {
        sum += a + (b - a) * (rand() / static_cast<float> (RAND_MAX));
    }

    return sum / n_events;
};