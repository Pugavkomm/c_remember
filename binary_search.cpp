#include <iostream>

template <typename T> 
int binary_search(T* arr, T key, int low, int high){
	if (low > high) return -1;
	int middle = (low + high) / 2;
	if (arr[middle] == key) return middle;
	if (arr[middle] > key)
		return binary_search(arr, key, low, middle - 1);
	else
		return binary_search(arr, key, middle + 1, high);
}
int main(){
	int size = 200000;
	int *arr = new int[size];
	for (int i = 0; i < size; ++i)
		arr[i] = i;
	std::cout << binary_search(arr, 80000, 0, size - 1) << std::endl;

	delete [] arr;
	return 0; 
}
