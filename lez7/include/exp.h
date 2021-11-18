#include <vector>

class exp_pdf {
    public:
    exp_pdf(double t_0);
    //~exp_pdf();
    double generate_exp();

    private:
    double __t_0;
    double inv_pdf(double y);
};