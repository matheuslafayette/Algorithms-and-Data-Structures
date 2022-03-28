#include "arrayStack.h"
#include <iostream>
using namespace std;

template <typename T> Stack<T> :: Stack(){

    this->maxSize = 1000;
    this->top = 0;
    this->stack = new T[maxSize];
}

template <typename T> Stack<T> :: ~Stack(){

    delete [] this->stack;
}

template <typename T> void Stack<T> :: clear(){

    this->top = 0;
}

template <typename T> void Stack<T> :: push(T value){

    if(this->top == maxSize)
        cout << "Stack is full" << endl;
    else{

        this->stack[this->top] = value;
        this->top++;
    }
}

template <typename T> T Stack<T> :: pop(){

    if(this->top == 0)
            cout << "Stack already empty" << endl;
    else{

        top--;
        return this->stack[this->top];
    }
        
}

template <typename T> T Stack<T> :: topValue(){

    if(this->top == 0)
        cout << "Empty stack" << endl;
    else
        return this->stack[this->top - 1];
}

template <typename T> int Stack<T> :: size(){

    return this->top;
}