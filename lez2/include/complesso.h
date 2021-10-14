#ifndef COMPLESSO_H
#define COMPLESSO_H

class complesso {
    public:
        complesso (double r, double i);
        complesso();
        ~complesso ();

        double modulo ();      
        double fase ();      

        complesso operator= (const complesso & orig);
        complesso operator+ (const complesso & addendo);
        complesso operator- (const complesso & minuendo);
        complesso operator* (const complesso & fattore);
        complesso operator/ (const complesso & dividendo);       

    private:
        double m_real;
        double m_imag;
};

#endif