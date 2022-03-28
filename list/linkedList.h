#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
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
//#include "node.h"

template < typename T > class List {

    private:
        int listSize;
        Node<T> *head;
        Node<T> *tail;
        Node<T> *curr;

    public:
        List();
        ~List();
        void clear();
        void insert(T);
        void append(T);
        T remove();
        void moveStart();
        void moveEnd();
        void prev();
        void next();
        int size();
        int currPos();
        void moveTo(int);
        T getValue();
        int equals(T);
        void printList();
        bool find(T);
};
#include "linkedList.cpp"
#endif