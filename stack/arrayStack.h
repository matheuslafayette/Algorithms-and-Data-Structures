#ifndef _STACK_H
#define _STACK_H

template < typename T > class Stack {

    private:
        int maxSize;
        int top;
        T *stack;

    public:
        Stack();
        ~Stack();
        void clear();
        void push(T);
        T pop();
        T topValue();
        int size();
};
#include "arrayStack.cpp"
#endif