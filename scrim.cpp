
//
//  scrim.cpp
//  beep
//
//  Created by Daniel Rivera on 1/3/18.
//

#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    
    for(int j = low; j <= high-1; j++){
        
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        
        quicksort(arr, low, pi -1);
        quicksort(arr, pi+1, high);
    }
}

void print(int arr[], int size){
    cout << size << " smallest elements:" << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int k;
    cin >> k;
    int arr[] = {10, 2, 5, 4, 7, 22, 9, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, size -1);
    print(arr, k);
    
    return 0;
}
