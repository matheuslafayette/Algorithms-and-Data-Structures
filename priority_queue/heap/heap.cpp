#ifndef HEAP_CPP
#define HEAP_CPP
#include "./../priority_queue.h"
#include <iostream>

template <typename Key, typename T> class Heap : public priority_queue<Key, T> {

private:

    KV<Key, T> *heap;
    int tam;

public:

    Heap(){

        this->heap = new KV<Key, T>[1000]();
        this->tam = 0;
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
            KV<Key, T> v;
            v.set(this->heap[k]);
            bool heapB = false;

            while(!heapB && 2*k <= this->tam){

                int j = 2 * k;
                
                if(j < this->tam && this->heap[j].key() < this->heap[j+1].key())
                    j++;
                
                if(v.key() >= this->heap[j].key())
                    heapB = true;
                
                else{

                    this->heap[k] = this->heap[j];
                    k = j;
                }
            }

            this->heap[k].set(v);
        }
    }


    T find_max(){

        return this->heap[1].value();
    }

};
#endif