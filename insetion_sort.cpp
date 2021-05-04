#include <iostream>
#include <utility>
template <typename T>
 Ж
void print_arr(const T* arr, size_t size){
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

template <typename T>
void insert_sort(T* arr, size_t size){
    size_t idx_i, idx_j;
    for (idx_i = 1; idx_i < size; ++idx_i){
        idx_j = idx_i;
        while ((idx_j > 0) && (arr[idx_j] < arr[idx_j - 1])){
            std::swap(arr[idx_j], arr[idx_j - 1]);
            idx_j -= 1;
        }
    }
}

int main(){
    size_t size = 15;
    int *arr;
    arr = new int[size];
    for (size_t i = 0; i < size; ++i){
        arr[i] = 1 + rand() % 100; 
    }
    print_arr(arr, size);
    insert_sort(arr, size);
    print_arr(arr, size);


    delete [] arr;
}
