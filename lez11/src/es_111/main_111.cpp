#include <iostream>
#include <vector>
#include <ctime>
#include <bits/stdc++.h>

#include <libLAB2/rand_num.h>
#include <libLAB2/pdf.h>

#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TFitResultPtr.h>


using namespace std;

double my_funct(double * x , double * par);

int main(int argc , char * argv[]) {
    
    double params[] = {2.0 , 3.0};

    rand_num my_rand;
    my_rand.set_seed(time(NULL));
    my_rand.set_max(10.0);
    
    pdf gauss;
    
       
    vector<double> x_rand;
    vector<double> y_rand;
    vector<double> x_var = {0. , 0. , 0. , 0. , 0. , 0. , 0. , 0. , 0. , 0.};
    vector<double> y_var = {0.5 , 0.5 , 0.5 , 0.5 , 0.5 , 0.5 , 0.5 , 0.5 , 0.5 , 0.5};

    for (int i = 0 ; i < 10 ; ++i) {
        double temp = my_rand.get_rnd();
        double error = gauss.generate_gauss(0 , 1 , 100);
        cout << error << endl;
        y_var.push_back(error);
        x_rand.push_back(temp);
        y_rand.push_back(my_funct(&temp , params) + error);
    }

    sort(x_rand.begin() , x_rand.end());
    sort(y_rand.begin() , y_rand.end());

    for (int i = 0 ; i < 10 ; ++i) {
        printf("Coppie: (%lf,%lf)\n" , x_rand[i] , y_rand[i]);
    }

    TF1 f_fit ("f_fit", my_funct , 0., 10. , 2) ;
    f_fit.SetParameters(params);

    TGraphErrors g_retta (x_rand.size(), &x_rand[0], &y_rand[0], &x_var[0], &y_var[0]);
    TFitResultPtr fit_result = g_retta.Fit (&f_fit, "S") ;

    TCanvas c1;
    g_retta.Draw();
    c1.Print("misc_output/es111.png" , "png");


    return 0;
}


double my_funct(double * x , double * par) {
    return par[0] + par[1] * x[0];
}