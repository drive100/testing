//
//  merge_sort.cpp
//  beep
//
//  Created by Daniel Rivera on 12/31/17.
//

#include "merge_sort.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

//
//  merge_sort.cpp
//  beep
//
//  Created by Daniel Rivera on 12/31/17.
//

#include "merge_sort.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void merge(int arr[], int low, int mid, int high){
    int i,j,k;
    int n1 = mid - low + 1; //the elements under the middle value
    int n2 = high - mid; // the elements above the middle value
    ////
    //temporary arrays
    int Lower[n1], Higher[n2]; //lower is values under the middle, higher is above the middle
    ///
    //copying in values
    for (i = 0; i < n1; i++){
        Lower[i] = arr[low+i]; //starts from the first value of the passed in array
    }
    for (j = 0; j < n2; j++){
        Higher[j] = arr[mid+1+j]; //copys values starting from the element above the middle
    }///
    
    //merge the temp arrays back to arr[low...high]
    i = 0; //initial index of first subarray
    j = 0; //initial index of second subarray
    k = low; //initial index of merged subarray
    
    while(i < n1 && j < n2){
        if (Lower[i] <= Higher[j]){
            arr[k] = Lower[i];
            i++;
        }
        else {
            arr[k] = Higher[j];
            j++;
        }
        k++;
    }
    
    //copy in any remaining values, ie. if the arrays are not equal length
    
    //for those lower than middle value
    while(i < n1){
        arr[k] = Lower[i];
        i++;
        k++;
    }
    //for those higher than middle value
    while(j < n2){
        arr[k] = Higher[j];
        j++;
        k++;
    }
    
}

void mergesort(int arr[], int low, int high){
    if (low < high){
        //int mid = low + (high - low)/2;  //same as (high+low)/2 but avoids overflow for large low & high
        int mid = (high+low)/2;
        
        mergesort(arr, low, mid); //sort first half
        mergesort(arr, mid+1, high); //sort second half
        
        merge(arr,low, mid, high);
    }
}

void print(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
  
    
    int arr[] = {9, 3, 6, 2, 5, 1, 4, 10, 14};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout << " Initial values " << endl;
    print(arr, size);
    
    mergesort(arr, 0, (size - 1));
    
    print(arr, size);
    
    
    return 0;
    
}

