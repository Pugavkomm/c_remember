#include <iostream> 

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp; 
    *yp = temp; 
}

void bubbleSort(int *arr, size_t n){
    int i, j;
    for (i = 0; i < n - 1; ++i){
        for (j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        
    }
}

void print(int *arr, size_t n){
    int i;
    for (i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

int main(){
    size_t size = 10;
    int *arr = new int[size]; 
    for (size_t i = 0; i < size; ++i)
        arr[i] = 1 + rand() % 15; 
    print(arr, size);
    bubbleSort(arr, size);
    print(arr, size);
    return 0;
}
