#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int main (int argc , char * argv[]) {
    std::string filename ("res/eventi_unif.txt");
    double data[10000];
    std::ifstream input_file;
    input_file.open (filename , std::ios::in);
    if (input_file.is_open() == false) {
        std::cout << "ERROR: " << strerror (errno)  << std::endl;
        return 1;
    }
    
    unsigned int i = 0;
    unsigned int pari_count = 0;
    double min_val = -1 , max_val = -1;    

    while (input_file >> data[i]) {
        if (static_cast<int> (data[i]) % 2 == 0 && pari_count != 10) {
            std::cout << "Num. pari: " << data[i] << std::endl;
            ++pari_count;
        }

        if (i < 10) {
            std::cout << "Num. : " << data[i] << std::endl;
        }

        if (i == 0) {
            min_val = data[i];
            max_val = data[i];
        } else if (data[i] > max_val) {
            max_val = data[i];
        } else if (data[i] < min_val) {
            min_val = data[i];
        }

        ++i;
    }

    input_file.close();
    unsigned int file_size = i;
    std::cout << "number of floats: " << file_size << std::endl;
    std::cout << "Max val: : " << max_val << std::endl;
    std::cout << "Min val: : " << min_val << std::endl;
    
    

    return 0;
}