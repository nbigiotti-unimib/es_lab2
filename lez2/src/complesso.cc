#include "../include/complesso.h"
#include <cmath>

complesso::complesso (double r , double i):
    m_real (r) ,
    m_imag (i)
    {};

complesso::complesso ():
    m_real (0.) ,
    m_imag (0.)
    {};

complesso::~complesso () {};

double complesso::modulo () {
    return  std::sqrt (m_real * m_real + m_imag * m_imag);
} 

double complesso::fase () {
    return  std::atan2 (m_imag , m_real);
}

double complesso::get_reale () {
    return m_real;
}

double complesso::get_immaginario () {
    return m_imag;
}

complesso complesso::operator= (const complesso & orig) {
    this -> m_imag = orig.m_imag;
    this -> m_real = orig.m_real;
    return *this;
}

complesso complesso::operator+ (const complesso & addendo) {
    complesso somma (m_real + addendo.m_real , m_imag + addendo.m_imag);
    return somma;
}

complesso complesso::operator- (const complesso & minuendo) {
    complesso differenza (m_real - minuendo.m_real , m_imag - minuendo.m_imag);
    return differenza;
}

complesso complesso::operator* (const complesso & fattore) {
    complesso prodotto (
        m_real * fattore.m_real - m_imag * fattore.m_imag ,
        m_real * fattore.m_imag + fattore.m_real * m_imag
    );
    return prodotto;
}

complesso complesso::operator/ (const complesso & divisore) {
    double denom = divisore.m_real * divisore.m_real + divisore.m_imag * divisore.m_imag;
    complesso quoziente (
        (m_real * divisore.m_real + m_imag * divisore.m_imag) / denom ,
        (- m_real * divisore.m_imag + divisore.m_real * m_imag) / denom
    );
    return quoziente;
}

complesso complesso::operator+= (const complesso & addendo) {
    return this -> operator+ (addendo);
}
complesso complesso::operator-= (const complesso & minuendo) {
    return this -> operator- (minuendo);
}
complesso complesso::operator*= (const complesso & fattore) {
    return this -> operator* (fattore);
}
complesso complesso::operator/= (const complesso & divisore) {
    return this -> operator/ (divisore);
}