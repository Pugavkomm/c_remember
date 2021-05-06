#include <iostream> 

template <typename T> 
void init_array_uniform(T *arr, size_t size){
    for (size_t i = 0; i < size; ++i){
        arr[i] = 1 + rand() % 15; 
    }
}

template <typename T> 
void merge(T *arr, size_t l, size_t m, size_t r){ 
    size_t n1, n2;

    n1 = m - l + 1;
    n2 = r - m; 

    T *left_arr, *right_arr; 
    left_arr = new T[n1];
    right_arr = new T[n2];

    for (size_t i = 0; i < n1; ++i)
        left_arr[i] = arr[l + i]; 

    for (size_t i = 0; i < n2; ++i)
        right_arr[i] = arr[m + 1 + i];

    size_t i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if (left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            ++i;
        }
        else {
            arr[k] = right_arr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1){
        arr[k] = left_arr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        ++j;
        ++k;
    }
    delete [] left_arr;
    delete [] right_arr; 

}
template <typename T> 
void mergeSort(T *arr, size_t l, size_t r){
    if (l >= r)
        return; 
    size_t meddian = l + (r - l) / 2; 
    mergeSort(arr, l, meddian);
    mergeSort(arr, meddian + 1, r);
    merge(arr, l, meddian, r); 
    
}

template <typename T> 
void print(T *arr, size_t size){
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}
int main(){
    size_t size = 10;
    int *arr = new int[size];
    init_array_uniform(arr, size); 
    mergeSort(arr, 0, size - 1);
    print(arr, size);

    delete [] arr; 
    return 0;
}
