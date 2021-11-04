#include </home/nicobigio01/repos/es_lab2/lez5/include/somma.h>
#include <iostream>

using namespace std;

int main (int argc , char * argv[]) {
    
    int a = 10 , b = 15;
    double da = 1.5 , db = 2.3;

    cout << "Somma di interi: " << somma(a , b) << endl;
    cout << "Somma di double: " << somma(da , db) << endl;    
    
    return 0;
}
