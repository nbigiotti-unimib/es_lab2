#include <iostream>

int fattoriale (int num);

int main(int argc , char * argv[]) {
	int N;
	std::cout << "Inserire il numero di cui si vuole calcolare il fattoriale" << std::endl;
	std::cin >> N;
	std::cout << "Il fattoriale vale: " << fattoriale(N) << std::endl;
	return 0;
}

int fattoriale (int num) {
	if(num == 1) {
		return 1;
	}

	return (num * fattoriale(num - 1));
}