#include <iostream>

int main (int argc , char * argv[]) {
	int a = 5;
	int b;
	int * ptr = &a;
	b = *ptr;
	std::cout << "valore di a: " << a << std::endl;
	std::cout << "valore di b: " << b << std::endl;
	std::cout << "indirizzo di a: " << &a << std::endl;
	std::cout << "indirizzo di b: " << &b << std::endl;
}
