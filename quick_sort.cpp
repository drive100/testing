//
//  quick_sort.cpp
//  beep
//
//  Created by Daniel Rivera on 12/31/17.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high){
    //int pivot = arr[((high - low )/ 2)];
    int pivot = arr[high];
    int i = (low - 1); //index of smaller element
    
    for (int j = low; j <= high -1; j++){
        
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i +1], &arr[high]);
    return (i +1);
    
}
//main function, arr[] to be sorted, low is starting index, high is ending index
void quicksort(int arr[], int low, int high){
    if (low < high){
        int partition_index = partition(arr, low, high); // arr[pi] is now at right place
        
        quicksort(arr, low, partition_index - 1);
        quicksort(arr, partition_index +1 , high);
    }
}


void print(int arr[], int x){
    cout << "Elements:\n";
    for (int i =0; i < x; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {5,10,4,7,1,9,0,21,43};
    int x = sizeof(arr)/sizeof(arr[0]);
    print(arr, x);
    quicksort(arr, 0, (x-1));
    print(arr, x);
    return 0;
}
