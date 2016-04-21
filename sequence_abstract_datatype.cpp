//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 6, Project 2 b
//  2/10/2016
//  sequence class for abstract datatype assuming it can be comparable datatype

#include <iostream>
#include "sequence_abstract_datatype.h"
using namespace std;

template<typename T>
sequence<T>::sequence() {
    data = new T[CAPACITY];
    used = 0;
    current_index = 0;
}

template<typename T>
void sequence<T>::start( ){
current_index = 0;
}

template<typename T>
void sequence<T>::advance( ){
current_index += 1;
}

template<typename T>
void sequence<T>::insert(const T& entry){
    for (int i=used; i > current_index; i--){
        data[i] = data[i-1];
    }
    data[current_index] = entry;
    used++;
}

template<typename T>
void sequence<T>::attach(const T& entry){
    for (int i=used; i > current_index + 1; i--){
        data[i] = data[i-1];
    }
    data[current_index +1] = entry;
    current_index++;
    used++;
}

template<typename T>
void sequence<T>::frontInsert(const T& entry){
    for (int i=used; i > -1; i--){
        data[i] = data[i-1];
    }
    data[0] = entry;
    used++;
}

template<typename T>
void sequence<T>::frontDelete(const T& entry){
    for (int i =0; i < used -1; i++){
        data[i] = data[i + 1];
    }
    used--;
}

template<typename T>
void sequence<T>::backInsert(const T& entry){
    data[used] = entry;
    used++;
}

template<typename T>
void sequence<T>::backDelete(const T& entry){
    data[used] = 0;
    used--;
}

template<typename T>
void sequence<T>::remove_current( ){
    if (current_index != 0){
        for (int i =current_index; i < used -1; i++){
            data[i] = data[i + 1];
        }
        used--;
    }
}

template<typename T>
typename sequence<T>::size_type sequence<T>::size( ){
    return used;
}

template<typename T>
bool sequence<T>::is_item( ){
    if(used ==0){
        return false;
    }else {
        return true;
    }
}

template<typename T>
typename sequence<T>::value_type sequence<T>::current( ) {
    return data[current_index];
}

template<typename T>
void sequence<T>::dump(){
    for(int i=0; i< used; i++){
        cout << "item: " << data[i] << endl;
    }
}

template<typename T>
sequence<T> sequence<T>::operator+=(const sequence& s1){
    if(used + s1.used <= CAPACITY){
        for (int i = 1; i < s1.used; i++){
            data[used+i] = s1.data[i];
        }
        used = used + s1.used;
    }
    return s1;
}

template<typename T>
sequence<T> sequence<T>::operator+(const sequence& s1)
{
    sequence<int> temp;
    for (int i = 0; i < s1.used; i++){
        temp.data[i] = s1.data[i];
        cout << "adding " << temp.data[i] << endl;
    }
    for (int i = 0; i < s1.used; i++){
        temp.data[used+i] = s1.data[i];
        cout << "adding " << temp.data[i] << endl;
    }
    temp.used  = used + s1.used;
    return temp;
}

int main()
{
   sequence<int> s;
   s.insert(10);
   s.insert(20);
   s.insert(30);
   cout << "s" << endl;
   s.dump();

   sequence<int> s1;
   s1.insert(40);
   s1.insert(50);
   s1.attach(10);

   sequence<int> s2;
   s2 = s + s1;
   cout << "s2" << endl;
   s2.dump();

}
