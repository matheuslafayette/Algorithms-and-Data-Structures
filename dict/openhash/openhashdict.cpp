#ifndef OPENHASHDICT_CPP
#define OPENHASHDICT_CPP
#include "./../dict.h"
#include <iostream>

//linked list based dict
template <typename Key, typename T> class Ldict : public Dict<Key, T> {

private:

    List< KV<Key, T> > *hash;

    int m; //hash table size
    int cont; //number elements dict
    int (*hf)(int){ nullptr };

public:

    Ldict(int size, int (*hashfunc)(int) ){
        
        this->m = size;
        this->cont = 0;

        this->hash = new List< KV<Key, T> >[size]();
            
        this->hf = hashfunc;
    }

    ~Ldict(){
        
        delete[] this->hash;
    }

    void clear(){

        for(int i = 0; i < this->m; i++)
            this->hash[i].clear();
    }

    int find(Key k){

        int pos = this->hf(k);
        int tam = this->hash[pos].size();

        this->hash[pos].moveStart();
        while(tam--){

            if(this->hash[pos].getValue().key() == k)
                return this->hash[pos].currPos();

            this->hash[pos].next();
        }
        return -1;
    }

    void insert(Key k, T v){

        if( this->find(k) == -1 ){

            int pos = this->hf(k);
            KV<Key, T> pair(k, v);
            this->hash[pos].append(pair);
            this->cont++;
        }
    }

    T remove(Key k){

        int pos = this->hf(k);
        int pos2 = this->find(k);

        if(pos2 == -1){

            cout << "ket not found" << endl;
            exit(1);
        }
            
        else{

            T aux;

            this->hash[pos].moveTo(pos2);
            aux = this->hash[pos].remove().value();
            this->cont--;

            return aux;
        }
    }

    int size(){

        return this->cont;
    }

    List<Key> getKeys(){

        List<Key> keys;
        int n = 0;

        for(int i = 0; i < this->m && n < this->cont; i++){

            int tam = hash[i].size();

            hash[i].moveStart();
            while(tam--){

                keys.append( hash[i].getValue().key() );
                hash[i].next();
                n++;
            }
        }
        keys.printList();
        return keys;
    }

    void printKeys(){

        for(int i = 0; i < this->m; i++){

            cout << i << " ";
            int tam = hash[i].size();

            hash[i].moveStart();
            while(tam--){

                cout << hash[i].getValue().key() << " ";
                hash[i].next();
            }
            cout << endl;
        }
    }
};
#endif