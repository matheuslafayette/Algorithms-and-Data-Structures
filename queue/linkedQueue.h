#ifndef _LINKEDQUEUE_H
#define _LINKEDQUEUE_H

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

template < typename T > class Queue {

    private:
        int tam;
        Node<T> *front;
        Node<T> *rear;

    public:
        Queue();
        ~Queue();
        void clear();
        void enqueue(T);
        T dequeue();
        T frontValue();
        int size();
};
#include "linkedQueue.cpp"
#endif