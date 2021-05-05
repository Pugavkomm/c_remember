#include <iostream>
using std::cout; 


template <typename T> 
void swap(T *xp, T *yp){
    T temp = *yp; 
    *yp = *xp; 
    *xp = temp; 
}

template <typename T> 
void quickSort(T *arr, size_t first, size_t last){
    if (first < last){
        size_t left = first; 
        size_t right = last; 
        T middle = arr[(left + right) / 2];
        do{
            while (arr[left] < middle)
                ++left; 
            while (arr[right] > middle) 
                --right; 

            if (left <= right) {
                swap(&arr[left], &arr[right]);
                ++left;
                --right; 
                
            }
            
        } while (left < right); 
        quickSort(arr, first, right);
        quickSort(arr, left, last); 
    }
}

template <typename T> 
void print_arr(T *arr, size_t size){ 
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << ' '; 
    cout << '\n'; 
}



int main(){
    size_t size = 10000000;
    int *arr = new int[size];

    for (size_t i = 0; i < size; ++i)
        arr[i] = 1 + rand() % 150; 
    
    //print_arr(arr, size); 
    quickSort(arr, 0, size - 1);
    print_arr(arr, size); 
    
    delete[] arr; 
    return 0;
}
    
  
