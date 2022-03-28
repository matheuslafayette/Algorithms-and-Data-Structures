#ifndef HEAP_CPP
#define HEAP_CPP
#include "./../dict.h"
#include <iostream>

template <typename Key, typename T> class Heap : public Dict<Key, T> {

private:

    KV<Key, T> *heap;
    int tam;


public:

    Heap(){

        this->heap = new KV<Key, T>[1000]();
        this->tam = 0
    }

    ~Heap(){

        delete[] heap;
    }

    void insert(Key k, T v){

        KV<Key, T> aux(k, v);
        this->tam += 1;
        this->heap[tam] = aux;
    }

    void heapBottomUp(){

        for(int i = this->tam/2; i >=1 ; i--){

            int k = i;
            int v = heap[k];
            bool heap = false;

            while(!heap && 2*k <= this->tam){

                int j = 2 * k;
                
            }
        }
    }

};
#endif