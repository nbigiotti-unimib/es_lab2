#include <vector>

class pdf {
    public:
    pdf();
    //~pdf();
    double generate_exp(double t_0);
    double generate_poisson(double lambda);

    private:
    double inv_exp_pdf(double y , double t_0);
};