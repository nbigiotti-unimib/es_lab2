#include "../../include/complesso.h"
#include <iostream>
#include <cmath>

int main (int argc , char * argv[]) {
    double img , real;
    
    std::cout << "Inserire parte immaginaria: " << std::endl;
    std::cin >> img;

    std::cout << "Inserire parte reale: " << std::endl;
    std::cin >> real;

    complesso comp_prova (real , img);

    std::cout << "Il modulo è: " << comp_prova.modulo() << std::endl;
    std::cout << "La fase è: " << comp_prova.fase() << std::endl;
}