//
//  subsets.cpp
//  beep
//
//  Created by Daniel Rivera on 12/31/17.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void printer(int arr[], int size){
   // cout << "{";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " , ";
    }
    cout << "" << endl;
}

void all_subsets(int arr[], int size){
    //cout << "{}" << endl;
   // printer(arr, size);
    int end = size - 1;
    int start = 0;
    int first_sweep =0;
    for (int i = 0; i < size; i++){
        cout << arr[i] << "," << endl;
    }
    for (int i = 0; i < (2^size); i++){
        while (start != size){
        cout << arr[i] << endl;
        }
        }
    }
    
}

int main(){
    int arr[] = {1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    all_subsets(arr, size);
    
    
    return 0;
}
