#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H

template < typename T > class Node {

    public:
        T value;
        Node *next;
        Node(T val, Node *nextVal = NULL){

            value = val;
            next = nextVal;
        }
        Node(Node *nextVal = NULL){

            next = nextVal;
        }
};

template < typename T > class Stack {

    private:
        int stackSize;
        Node<T> *top;

    public:
        Stack();
        ~Stack();
        void clear();
        void push(T);
        T pop();
        T topValue();
        int size();
};
#include "linkedStack.cpp"
#endif