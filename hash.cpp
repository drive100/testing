//
//  hash.cpp
//  beep
//
//  Created by Daniel Rivera on 12/30/17.
//

#include "hash.hpp"
#include <iostream>
#include <string>

using namespace std;
class hash1{
private:
    static const int tableSize = 4;
    
    struct item{
        string name;
        string drink;
        item* next;
    };
    
    item* HashTable[tableSize];
public:
    hash1();
    ~hash1();
    int hasher(string key);
    void add_item(string name, string drink);
    int number_of_items_in_index(int index);
    void print_table();
    void print_items_in_index(int index);
    void find_drink(string name);
    void remove(string name);
    
};

///////////////////////////////////////////////////////////////////
int main(){
    //hash1 h1;
    //int index;
    //index = h1.hasher("beep");
    //cout << "index = " << index << endl;
    hash1 hashy;
    //hashy.print_table();
    string name = "";
    
    hashy.add_item("Meow", "soda");
    hashy.add_item("boop", "juice");
    hashy.add_item("beep", "water");
    hashy.add_item("Meer", "chemicals");
    hashy.add_item("Daniel", "chicha");
    
    hashy.print_table();
    //hashy.print_items_in_index(2);
    
    while (name != "exit"){
        cout << "Remove: ";
        cin >> name;
        if (name != "exit"){
            hashy.remove(name);
        }
        if (name == "print"){
            hashy.print_table();
        }
    }
    //hashy.print_table();
    return 0;
    
}
///////////////////////////////////////////////////////////////////
hash1::hash1(){
    for (int i = 0; i <tableSize; i++){
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = nullptr;
    }
}
hash1::~hash1(){
    item *ptr;
    for(int i = 0; i<tableSize; i++){
        while(HashTable[i] != nullptr){
            ptr = HashTable[i];
            HashTable[i] = HashTable[i]->next;
            delete ptr;
        }
    }
}
int hash1::hasher(string key){
    //int index;
    //index = key.length();
    //return index;
    int hash = 0;
    int index;
    
    //index = key.length();
    
    for (int i = 0; i < key.length(); i++){
        hash = (hash + (int)key[i]) * 10;
        //cout << "hash = " << hash << endl;
    }
    
    index = hash % tableSize;
    

    return index;
}
void hash1::add_item(string name, string drink){
    int index = hasher(name);
    if (HashTable[index]->name == "empty"){
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else{
        item* ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = nullptr;
        
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}
int hash1::number_of_items_in_index(int index){
    int count = 0;
    if (HashTable[index]->name == "empty"){
        return count;
    }
    else{
        count++;
        item* ptr = HashTable[index];
        while(ptr->next != nullptr){
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}
void hash1::print_table(){
    int number;
    
    for(int i = 0; i < tableSize; i++){
        number = number_of_items_in_index(i);
        cout << "----------------------\n";
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink << endl;
        cout << "number of items = " << number << endl;
        cout << "----------------------\n";
    }
}
void hash1::print_items_in_index(int index){
    item * ptr = HashTable[index];
    
    if (ptr->name == "empty"){
        cout << "no hay nada in el indexo " << index << endl;
    }
    else{
        cout << "index " << index << " tiene estos cosas\n";
        
        while(ptr != nullptr){
            cout << "---------------\n";
            cout << ptr->name << endl;
            cout << ptr->drink << endl;
            cout << "---------------\n";
            ptr = ptr->next;
        }
    }
}
void hash1::find_drink(string name){
    int index = hasher(name);
    bool found = false;
    string drink;
    
    item* ptr = HashTable[index];
    
    while(ptr != nullptr){
        if (ptr->name == name){
            found = true;
            drink = ptr->drink;
        }
        ptr = ptr->next;
    }
    if (found == true){
        cout << "favorite drink = " << drink << endl;
    }
    else
        cout << "Entry for " << name << " does not exist" << endl;
}
void hash1::remove(string name){
    int index = hasher(name);
    item* delptr;
    item* p1;
    item* p2;
    
    //case 0  - bucket is empty
    if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty"){
        cout << name << " not found." << endl;
    }
    //case 1  - only 1 item in bucket, and its a match
    else if (HashTable[index]->name == name && HashTable[index]->next == nullptr){
        HashTable[index]->name = "empty";
        HashTable[index]->drink = "empty";
        cout << name << " has been removed." << endl;
    }
    //case 2  - match is first item in bucket, but there are multiple matches in the bucket
    else if (HashTable[index]->name == name){
        delptr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delptr;
        
        cout << name << " has been removed." << endl;
    }
    //case 3  - bucket contains items but first item is not a match
    else{
        p1 = HashTable[index]->next;
        p2 = HashTable[index];
        
        while(p1 != nullptr && p1->name != name){
            p2 = p1;
            p1 = p1->next;
        }
        //case 3.1 - looked through all items, no match
        if (p1 == nullptr){
            cout << name << " not found." << endl;
        }
        //case 3.2 - find a match but not the first item
        else{
            delptr = p1;
            p1 = p1->next;
            p2->next = p1;
            delete delptr;
            cout << name << " has been removed." << endl;
        }
    }
    
    
    
    
}
