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