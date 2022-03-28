#include "linkedQueue.h"
#include <iostream>
using namespace std;

template <typename T> Queue<T> :: Queue(){

    this->front = this->rear = new Node<T>(NULL);
    this->tam = 0;
}

template <typename T> Queue<T> :: ~Queue(){

    this->clear();
    delete this->front;
}

template <typename T> void Queue<T> :: clear(){

    while(this->tam != 0)
        this->dequeue();
    
}

template <typename T> void Queue<T> :: enqueue(T val){

    this->rear->next = new Node<T>(val, NULL);
    this->rear = this->rear->next;
    this->tam++;
}

template <typename T> T Queue<T> :: dequeue(){

    if(tam == 0){

        cout << "Queue is empty!" << endl;
        exit(1);
    }
    Node<T> *aux1 = this->front->next;
    T auxReturn = this->front->next->value;

    this->front->next = this->front->next->next;
    delete aux1;

    if(this->front->next == NULL)
        this->rear = this->front;

    this->tam--;
    return auxReturn;
}

template <typename T> T Queue<T> :: frontValue(){

    if(this->tam == 0){

        cout << "Queue is empty!" << endl;
        exit(1);
    }
    return this->front->next->value;
}

template <typename T> int Queue<T> :: size(){

    return (this->tam);
}