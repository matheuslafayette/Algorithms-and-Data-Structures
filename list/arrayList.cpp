#include "arrayList.h"
#include <iostream>
#include <limits.h>
using namespace std;

template <typename T>  List<T> :: List(){

    this->maxSize = 1000;
    this->listSize = 0;
    this->curr = 0;
    this->list = new T[this->maxSize];
}

template <typename T> List<T> :: ~List(){

    delete[] list;
}

template <typename T> void List<T> :: clear(){

    delete[] list;
    this->curr = 0;
    this->listSize = 0;
}

template <typename T> void List<T> :: insert(T value){

    if(this->listSize < this->maxSize){

        int i = this->listSize - 1;

        while( i >= this->curr ){

            this->list[i+1] = this->list[i];
            i--;
        }
        this->list[this->curr] = value;
        this->listSize++;
    }
}

template <typename T> void List<T> :: append(T value){

    if(listSize < maxSize){

        this->list[this->listSize++] = value;
    }
}

template <typename T> T List<T> :: remove(){

    if(this->curr < this->listSize){

        T aux = this->list[this->curr];
        int i = this->curr;
        while(i < this->listSize - 1){

            this->list[i] = this->list[i+1];
            i++;
        }
        this->listSize--;
        return aux;
    }
    return INT_MIN;
}

template <typename T> void List<T> :: moveStart(){

    this->curr = 0;
}

template <typename T> void List<T> :: moveEnd(){

    this->curr = this->listSize - 1;
}

template <typename T> void List<T> :: prev(){

    if(this->curr > 0)
        this->curr--;
}

template <typename T> void List<T> :: next(){

    if( this->curr < this->listSize )
        this->curr++;
}

template <typename T> int List<T> :: size(){

    return this->listSize;
}

template <typename T> int List<T> :: currPos(){

    return this->curr;
}

template <typename T> void List<T> :: moveTo(int pos){

    if(pos >= 0 && pos <= this->listSize)
        this->curr = pos;
}

template <typename T> T List<T> :: getValue(){

    return this->list[this->curr];
}

template <typename T> int List<T> :: equals(T value){

    int cont = 0;
    for(int i = 0; i < this->listSize; i++){

        if(this->list[i] == value)
            cont++;
    }
    return cont;
}

template <typename T> void List<T> :: printList(){

    for(int i = 0; i < this->listSize; i++){

        cout << this->list[i] << " ";
    }
    cout << endl;
}