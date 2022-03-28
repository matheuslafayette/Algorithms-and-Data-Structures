#ifndef _DICT_H
#define _DICT_H
#include "./../list/linkedList.h"
template <typename Key, typename T> class KV{

    private:
        Key k;
        T v;
    
    public:
        KV(Key key, T value){

            this->k = key;
            this->v = value;
        }
        
        KV() {}

        Key key(){

            return this->k;
        }
        T value(){

            return this->v;
        }     
};

template <typename Key, typename T> class Dict{

    public:
        Dict() {};//foi
        ~Dict() {};
        void clear();
        void insert(Key, T);//foi
        T remove(Key);//foi
        List<Key> getKeys();
        int find(Key);//foi
        T findbst(Key);//foi
        int size();//foi
        void printKeys();
};
#include "./openhash/openhashdict.cpp"
#include "./closedhash/closedhashdict.cpp"
#include "./bst/bst.cpp"
#include "./adt/adt.cpp"
#include "./heap/heap.cpp"
#endif