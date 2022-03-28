#ifndef _NODE_H
#define _NODE_H
#include <iostream>

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
#include "linkedList.cpp"
#endif