#include <iostream>


void SortArray (double * myArray, int dim) ;

int main (int argc , char * argv[]) {
	int N = -1;

	std::cout << "Inserire la grandezza dell'array: " << std::endl;
	std::cin >> N;

	double * arr = new double [N];

	for (int i = 0 ; i < N ; i += 1) {
		std::cout << "Inserire i valori dell'array: " << std::endl;
		std::cin >> arr[i];	
	}

	SortArray(arr , N);


	std::cout << "L'array ordinato è: " << std::endl;
	for (int i = 0 ; i < N ; i += 1) {
		std::cout << arr[i] << std::endl;
	}

	delete[] arr;
	return 0;
}

void swap(double * my_arr , int pos1 , int pos2) {
	double temp = -1;
	temp = my_arr[pos2];
	my_arr[pos2] = my_arr[pos1];
	my_arr[pos1] = temp;
	return;
}

void SortArray (double * my_arr, int dim) {
	double min = -1;
	int min_pos;
	for(int k = 0 ; k < dim ; k += 1) {
		min = my_arr[k];
		min_pos = k;
		for(int i = k + 1 ; i < dim ; i += 1) {
			if(my_arr[i] < min ) {
				min_pos = i;
				min = my_arr[i];
			}
		}
		swap(my_arr , k , min_pos);
	}
	return;
}
