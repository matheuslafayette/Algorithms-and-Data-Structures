#include "arrayQueue.h"
#include <iostream>
using namespace std;

template <typename T> Queue<T> :: Queue(int tam){

    this->maxSize = tam + 1;
    this->rear = this->front = 0;
    this->queue = new T[maxSize];
}

template <typename T> Queue<T> :: ~Queue(){

    delete [] this->queue;
}

template <typename T> void Queue<T> :: clear(){

    this->rear = this->front = 0;
}

template <typename T> void Queue<T> :: enqueue(T val){

    if((this->rear + 1) % maxSize == this->front){

        cout << "Queue is full!" << endl;
        exit(1);
    }
    this->queue[this->rear] = val;
    this->rear = (this->rear + 1) % maxSize;
}

template <typename T> T Queue<T> :: dequeue(){

    if( this->rear % maxSize == this->front ){

        cout << "Queue is empty!" << endl;
        exit(1);
    }
    
    T aux = this->queue[this->rear];
    this->front = (this->front + 1) % maxSize;
    return aux;
        
}

template <typename T> T Queue<T> :: frontValue(){

    if( this->rear % maxSize == this->front ){

        cout << "Empty queue!" << endl;
        exit(1);
    }   
    
    return this->queue[ this->front ];
}

template <typename T> int Queue<T> :: size(){

    return (( rear + maxSize - front ) % maxSize);
}