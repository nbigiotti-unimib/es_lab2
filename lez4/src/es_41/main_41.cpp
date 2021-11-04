#include <iostream>


int main (int argc , char * argv[]) {
    int M = 2147483647;
    int A = 214013;
    int C = 2531011;

    int num;
    int seed;

    num = seed;
    char control;

    while(control != 'q') {
        num = (A * num + C) % M;
        std::cout << num << std::endl;
        std::cin >> control;
    }    

    return 0;
}
