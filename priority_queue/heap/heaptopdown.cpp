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
 
        this->heap = new KV<Key, T>[101000]();
        this->tam = 0;
    }
 
    ~Heaptd(){
 
        delete[] heap;
    }
    
    void heapify(int index){

        KV<Key, T> v;
        v.set(this->heap[index]);

        bool heapB = false;
        int k = index;
        
        while(!heapB && 2*k <= this->tam){
                
            int j = 2 * k;
            
            if(j < this->tam && this->heap[j].key() < this->heap[j+1].key())
                j++;
            
            if(v.key() >= this->heap[j].key())
                heapB = true;
            
            else{
                
                this->heap[k].set(this->heap[j]);
                k = j;
            }
        }

        this->heap[k].set(v);
    }

    void insert(Key key, T value){
 
        KV<Key, T> aux(key, value);
        this->heap[++this->tam] = aux;
 
        for(int i = this->tam / 2; i >= 1; i /= 2)
            this->heapify(i);
 
    }
 
    T find_max(){
        
        if(this->tam == 0)
            return NULL;
            
        return this->heap[1].value();
    }
 
    T remove_max(){
 
        if(this->tam == 0)
            return NULL;
 
        T ret = this->heap[1].value();
 
        this->heap[1].set(this->heap[this->tam--]);
 
        this->heapify(1);
    
        return ret;
    }
    
    void printHeap(){

        for(int i = 1; i <= this->tam; i++) 
            cout << this->heap[i].value() << " ";
        
        cout << endl;
    }
 
    int size(){
 
        return this->tam;
    }
 
};
#endif