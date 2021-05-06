#include <iostream>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp; 
}

void heapify(int *arr, size_t size, size_t i) {
    size_t largest = i; 
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2; 

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]); 
        heapify(arr, size, largest); 
    }
}

void heapSort(int *arr, size_t size){
    for (int i = size / 2 - 1; i >= 0; --i){
        heapify(arr, size, i) ;
    }

    for (int i = size  - 1; i >= 0; --i){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void print_arr(int *arr, size_t size){
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

void init_array_uniform(int *arr, size_t size){
    for (size_t i = 0; i < size; ++i){
        arr[i] = 1 + rand() % 15; 
    }
}
int main(){
    size_t size = 100; 
    int *arr;
    arr = new int[size]; 
    init_array_uniform(arr, size);
    print_arr(arr, size);
    std::cout << '\n';
    heapSort(arr, size);
    print_arr(arr, size);

   

    delete [] arr; 

    
    return 0;
}
