#include "matrici.h"
#include <iostream>
#include <cmath>

vettore2::vettore2 (double a , double b): 
    m_vtr {a , b}
    {}

void vettore2::print () const {
    
    std::cout << "/" << m_vtr[0] << "\\" << std::endl;
    std::cout << "\\" << m_vtr[1] << "/" << std::endl;

    return;
}


matrice2x2::matrice2x2 (double a11, double a12, double a21, double a22) :
    m_mtr {{a11 , a12} , {a21 , a22}}
    {}

matrice2x2::matrice2x2 (double angolo) {
    m_mtr[0][0] = cos(angolo);
    m_mtr[1][1] = cos(angolo);
    m_mtr[0][1] = - sin(angolo);
    m_mtr[1][0] = sin(angolo);
    return;
}

void matrice2x2::print () const {
    std::cout << "/" << m_mtr[0][0] << " " << m_mtr[0][1] << "\\" << std::endl;
    std::cout << "\\" << m_mtr[1][0] << " " << m_mtr[1][1] << "/" << std::endl;
}

matrice2x2 matrice2x2::operator* (const matrice2x2 & seconda) const {
    matrice2x2 prodotto (
        this->m_mtr[0][0] * seconda.elem(0 , 0) + this->m_mtr[0][1] * seconda.elem(1 , 0) ,
        this->m_mtr[0][0] * seconda.elem(0 , 1) + this->m_mtr[0][1] * seconda.elem(1 , 1) ,
        this->m_mtr[1][0] * seconda.elem(0 , 0) + this->m_mtr[1][1] * seconda.elem(1 , 0) ,
        this->m_mtr[1][0] * seconda.elem(0 , 1) + this->m_mtr[1][1] * seconda.elem(1 , 1)
    );

    return prodotto;
}

vettore2 operator* (const matrice2x2 & prima, const vettore2 & secondo) {
    vettore2 prodotto (
        prima.elem(0 , 0) * secondo.elem(0) + prima.elem(0 , 1) * secondo.elem(1) ,
        prima.elem(1 , 0) * secondo.elem(0) + prima.elem(1 , 1) * secondo.elem(1)
    );

    return prodotto;
}