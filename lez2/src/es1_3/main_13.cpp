#include "../../include/complesso.h"
#include <iostream>
#include <cmath>

int main (int argc , char * argv[]) {
    double img , real;
    
    std::cout << "Inserire parte immaginaria: " << std::endl;
    std::cin >> img;

    std::cout << "Inserire parte reale: " << std::endl;
    std::cin >> real;

    complesso comp_prova1 (real , img);

    std::cout << "Inserire parte immaginaria: " << std::endl;
    std::cin >> img;

    std::cout << "Inserire parte reale: " << std::endl;
    std::cin >> real;

    complesso comp_prova2 (real , img);


    std::cout << "Il modulo è: " << comp_prova1.modulo() << std::endl;
    std::cout << "La fase è: " << comp_prova1.fase() << std::endl;

    complesso somma = comp_prova1 + comp_prova2;
    complesso differenza = comp_prova1 - comp_prova2;
    complesso prodotto = comp_prova1 * comp_prova2;
    complesso quoziente = comp_prova1 / comp_prova2;

    std::cout << "La somma è: " << somma.get_reale() << "+" << somma.get_immaginario() << "i" << std::endl;
    std::cout << "La differenza è: " << differenza.get_reale() << "+" << differenza.get_immaginario() << "i" << std::endl;
    std::cout << "Il prodotto è: " << prodotto.get_reale() << "+" << prodotto.get_immaginario() << "i" << std::endl;
    std::cout << "Il quoziente è: " << quoziente.get_reale() << "+" << quoziente.get_immaginario() << "i" << std::endl;

    comp_prova1 += comp_prova2;
    std::cout << "La somma è: " << comp_prova1.get_reale() << "+" << comp_prova1.get_immaginario() << "i" << std::endl;

    comp_prova1 -= comp_prova2;
    std::cout << "La somma è: " << comp_prova1.get_reale() << "+" << comp_prova1.get_immaginario() << "i" << std::endl;

    comp_prova1 *= comp_prova2;
    std::cout << "La somma è: " << comp_prova1.get_reale() << "+" << comp_prova1.get_immaginario() << "i" << std::endl;

    comp_prova1 /= comp_prova2;
    std::cout << "La somma è: " << comp_prova1.get_reale() << "+" << comp_prova1.get_immaginario() << "i" << std::endl;

}