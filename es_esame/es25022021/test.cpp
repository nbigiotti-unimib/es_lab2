#include "matrici.h"

int main () {
    matrice2x2 first (1. , -2. , 2. , 1.);
    matrice2x2 second (3.1415);

    vettore2 vec(2. , 3.);

    first.print();
    second.print();
    vec.print();

    matrice2x2 res = first * second;
    vettore2 res2 = first * vec;

    res.print();
    res2.print();

    return 0;
}