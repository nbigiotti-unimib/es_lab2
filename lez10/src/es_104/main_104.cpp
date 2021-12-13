#include <iostream>
#include <vector>

#include <TH1F.h>
#include <TCanvas.h>

#include <libLAB2/pdf.h>

using namespace std;

double get_max (
  double logl(const vector<double> & data , double param),
  double xMin,
  double xMax,
  const vector<double> & data,
  double precision
);

double get_zeroes(
	double logl(const vector<double> & data , double param),
	double xMin,
	double xMax,
	const vector<double> & data,
	double precision
);

double loglikelihood (
  const vector<double> & data,
  double param
);

int main(int argc , char * argv[]) {
	pdf esp;
	int n_eventi = 10000;
	double t_0 = 1.5;
	vector<double> esp_data;

	TH1F ist ("ist" , "ist" , 1000 , 0 , 15);

	for(int i = 0 ; i < n_eventi ; ++i) {
		double temp = esp.generate_exp(t_0);
		esp_data.push_back(temp);
		ist.Fill(temp);
	}

	double max = get_max(loglikelihood , 0.5 * t_0 , 1.5 * t_0 , esp_data , 0.0001);

	double z1 = get_zeroes(loglikelihood , 0.5 * t_0 , t_0 , esp_data , 0.0001);
	double z2 = get_zeroes(loglikelihood , t_0 , 5 * t_0 , esp_data , 0.0001);
	double sigma = (z2 - z1) / 2.;

	std::cout << "t_0 = " << max << std::endl;
	std::cout << "sigma = " << sigma << std::endl;
	std::cout << "t_0 = " << ist.GetMean() << std::endl;
	std::cout << "sigma = " << ist.GetStdDevError() << std::endl;
	return 0;
}

double esponenziale (double x, double tau) {
     if (tau == 0.) return 1. ;
     return exp (-1. * x / tau) / tau ;
}

double loglikelihood (
  const vector<double> & data,
  double param
)
{
  double result = 0. ;
  for (int i = 0 ; i < data.size () ; ++i)
  	result += log (esponenziale (data.at (i), param));
  return result ;   
}

double get_max (
  double logl(const vector<double> & data , double param),
  double xMin,
  double xMax,
  const vector<double> & data,
  double precision
)
{
	double x[4];
	double r = 0.618;
	double y[4];
	double par[] = {1 , 100};

	x[0] = xMin;
	x[3] = xMax;
	x[2] = x[0] + r * (x[3] - x[0]);
	x[1] = x[0] + (1 - r) * (x[3] - x[0]);
	while((x[3] - x[0]) > precision) {
		for (int i = 0 ; i < 4 ; ++i) {
			y[i] = logl(data , x[i]);
		}

		if(((y[1] - y[0]) * (y[2] - y[1])) < 0 ) {
			x[3] = x[2];
			x[2] = x[1];
			x[1] = x[0] + (1 - r) * (x[3] - x[0]);
		} else {
			//elimina primo intervallo
			x[0] = x[1];
			x[1] = x[2];
			x[2] = x[0] + r * (x[3] - x[0]);
		}

	}
	return (x[0] + x[3]) / 2.;
}

double get_zeroes(
	double logl(const vector<double> & data , double param),
	double xMin,
	double xMax,
	const vector<double> & data,
	double precision
) {
	double interv[3] = {xMin , (xMax + xMin) / 2.0 , xMax};

	while (interv[2] - interv[0] > precision) {
		if (((logl(data , interv[0]) - logl(data , 1.5) + 0.5) * (logl(data , interv[1]) - logl(data , 1.5) + 0.5)) < 0) {
			interv[2] = interv[1];
			interv[1] = (interv[0] + interv[2]) / 2.0;
		} else {
			interv[0] = interv[1];
			interv[1] = (interv[0] + interv[2]) / 2.0;
		}
	}
	
	return (interv[0] + interv[3]) / 2.;
}