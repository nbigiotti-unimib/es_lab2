#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

//Queste funzioni non devono essere accessibili al programma principale
static double triangle_pdf (double x);
static double rand_range(double min , double max);

//Genera un numero casuale x_i compreso fra x_min e x_max
//utilizzando il metodo try-catch
double triangle_tac (double x_min , double x_max) {
    double y_max {2. / 3.};
    double x , y;
    do {
        x = rand_range(x_min , x_max);
        y = rand_range(0. , y_max);
    } while (y > triangle_pdf(x));
        
    return x;
}

//Calcola la media del campione `sample`
double mean (vector<double> & sample) {
    double mean {0.};
    for (vector<double>::iterator it = sample.begin() ; it != sample.end() ; ++it) {
        mean += *it;
    }
    return mean / static_cast<double> (sample.size());
}

//Calcola la deviazione standard del campione `sample`
//utilizza la correzione di Bessel per ottenere stimatore
//non distorto
double std_dev_bessel (vector<double> & sample , double mean) {
    double std_dev {0.};
    for (vector<double>::iterator it = sample.begin() ; it != sample.end() ; ++it) {
        std_dev += (*it - mean) * (*it - mean);
    }
    return sqrt (std_dev / static_cast<double> (sample.size() - 1));
}

//Genera numeri pseudocasuali secondo pdf uniforme
//compresi fra `min` e `max`
static double rand_range(double min , double max) {  
    return min + (rand() / static_cast<double> (RAND_MAX)) * (max - min);
}

//Funzione analitica della pdf triangolare
static double triangle_pdf (double x) {
    //Il valore `k` del coefficiente angolare
    //è fissato dalle condizioni di normalizzazione
    //della pdf
    double k {2. / 9.};

    if (x < 0 || x > 3) {
        return 0.;
    }
    return k * x;
}