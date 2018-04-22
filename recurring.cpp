//
//  recurring.cpp
//  beep
//
//  Created by Daniel Rivera on 12/31/17.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct node{
    node(char x, int a){ c = x; count = a;}
    char c;
    int count;
};


void checker(char x, map<char,int> m){
    map<char,int>::iterator it;
    it = m.find(x);
    if (it == m.end()){
        m[x] = 1;
        //cout << "meow";
    }
    else{
        cout << "First recurring: " << x << endl;
    }
    //m.insert(x,1);
}
void recurring(string x, map<char,int> m){
    
    for (int i =0; i < x.length(); i++){
        checker(x[i], m);
    }

}

int main(){
    vector <node> v1;
    map<char, int> m1;
    string x;
    cout << "Enter string: ";
    cin >> x;
    
    recurring(x, m1);
    
    
    
    
    return 0;
}
