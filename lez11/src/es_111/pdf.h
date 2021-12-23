#include <vector>

class pdf {
    public:
    pdf();
    //~pdf();
    double generate_exp(double t_0);
    double generate_poisson(double lambda);
    double generate_gauss(double media , double sigma , int n_events);

    private:
    double inv_exp_pdf(double y , double t_0);
};