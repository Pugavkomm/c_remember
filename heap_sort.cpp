#include <iostream>

void heapfy(int arr[], int n, int i){
    int largest = i;
    int l = 2 * i + 1; // left = 2 * i + 1
    int r = 2 * i + 2; // right = 2 * i + 2

    if (l < n && arr[l] > arr[largest])
        largest = 1;

    if (r < n && arr[r] > arr[largest])
        largest = r; 
}

int main(){
    return 0;
}
