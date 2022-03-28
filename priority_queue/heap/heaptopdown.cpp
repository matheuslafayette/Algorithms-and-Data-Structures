#ifndef HEAPTD_CPP
#define HEAPTD_CPP
#include "./../priority_queue.h"
#include <iostream>

template <typename Key, typename T> class Heaptd : public priority_queue<Key, T> {

private:

    KV<Key, T> *heap;
    int tam;


public:

    Heaptd(){

        this->heap = new KV<Key, T>[10000]();
        this->tam = 0;
    }

    ~Heaptd(){

        delete[] heap;
    }

    void insert(Key key, T value){

        KV<Key, T> aux(key, value);
        this->heap[++this->tam] = aux;

        int i = this->tam;
        int k = i;

        while(i > 1 && this->heap[i/2].key() > this->heap[i].key()){

            this->heap[i].set(this->heap[i/2]);
            i /= 2; 
        }

        this->heap[i].set(aux);

    }

    T find_max(){

        return this->heap[1].value();
    }

    T remove_max(){

        if(this->tam == 0)
            exit(1);
            
        T ret = this->heap[1].value();

        this->heap[1].set(this->heap[this->tam]);
        --this->tam;

        KV<Key, T> v;
        v.set(this->heap[1]);

        bool heapB = false;
        int k = 1;
        
        while(!heapB && 2*k <= this->tam){
                
            int j = 2 * k;
            
            if(j < this->tam && this->heap[j].key() > this->heap[j+1].key())
                j++;
            
            if(v.key() <= this->heap[j].key())
                heapB = true;
            
            else{
                
                this->heap[k] = this->heap[j];
                k = j;
            }
        }

        this->heap[k].set(v);
    
        return ret;
    }

};
#endif