//Nicolas Bigiotti - 865437

#ifndef LIB_H
#define LIB_H

#include <vector>

using namespace std;

double triangle_tac (double x_min , double x_max);
double mean (vector<double> & sample);
double std_dev_bessel (vector<double> & sample , double mean);

#endif //LIB_H