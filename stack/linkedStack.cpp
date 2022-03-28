#include "linkedStack.h"
#include <iostream>
using namespace std;

template <typename T>  Stack<T> :: Stack(){

    this->top = new Node<T>();
    this->stackSize = 0;
}

template <typename T> Stack<T> :: ~Stack(){

    this->clear();
}

template <typename T> void Stack<T> :: clear(){

    while(this->top != NULL){

        Node<T> *aux = this->top;
        this->top = this->top->next;
        delete aux;
    }
}

template <typename T> void Stack<T> :: push(T val){

    this->top = new Node<T>(val, this->top);
    this->stackSize++;
}

template <typename T> T Stack<T> :: pop(){

    if(this->top == NULL){
        
        cout << "Stack is empty" << endl;
        exit(1);
    }
        
    else{

        T aux = this->top->value;
        Node<T> *aux2 = this->top;
        this->top = this->top->next;
        delete aux2;
        this->stackSize--;

        return aux;
    }  
}

template <typename T> T Stack<T> :: topValue(){

    if(this->top == NULL){

        cout << "Stack is empty" << endl;
        exit(1);
    }
        
    else
        return top->value;
}

template <typename T> int Stack<T> :: size(){

    return stackSize;
}