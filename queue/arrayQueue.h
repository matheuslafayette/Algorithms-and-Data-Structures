#ifndef _ARRAYQUEUE_H
#define _ARRAYQUEUE_H

template < typename T > class Queue {

    private:
        int maxSize;
        int front;
        int rear;
        T *queue;

    public:
        Queue(int tam = 1000);
        ~Queue();
        void clear();
        void enqueue(T);
        T dequeue();
        T frontValue();
        int size();
};
#include "arrayQueue.cpp"
#endif