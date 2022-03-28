#ifndef CLOSEDHASHDICT_CPP
#define CLOSEDHASHDICT_CPP
#include "./../dict.h"
#include <iostream>

//linked list based dict
template <typename Key, typename T> class Cdict : public Dict<Key, T> {

private:

    List< KV<Key, T> > *hash;
    List<int> *perm;

    int m; //hash table size
    int cont; //number elements dict
    int (*hf)(Key){ nullptr };
    Key nullK;
    T nullV;

public:

    Cdict(int size, int (*hashfunc)(Key), Key nullKey, T nullValue ){
        
        this->m = size;
        this->cont = 0;
        this->nullK = nullKey;
        this->nullV = nullValue;

        this->hash = new List< KV<Key, T> >();

        KV<Key, T> nullKV(nullKey, nullValue);
        for(int i = 0; i < this->m; i++)
            this->hash->append(nullKV);

        this->perm = new List<int>();

        //linear probing
        for(int i = 0; i < size-1; i++)
            this->perm->append(i+1);
            
        this->hf = hashfunc;
    }

    ~Cdict(){
        
        delete this->hash;
        delete this->perm;
    }

    void clear(){

        hash->moveStart();
        KV<Key, T> nullKV(nullK, nullV);

        for(int i = 0; i < this->m; i++)
            this->hash->remove();

        for(int i = 0; i < this->m; i++)
            this->hash->append(nullKV);
    }

    int find(Key k){
 
        int init = hf(k);
        hash->moveTo(init);

        int tam = this->m - 1;
        perm->moveStart();
        int curr = init;

        while(tam--){

            if(hash->getValue().key() == k)
                return curr;
            
            curr = ( init + perm->getValue() ) % this->m;
            hash->moveTo( curr );
            perm->next();
        }
        return -1;
    }

    void insert(Key k, T v){

        if( this->find(k) == -1 && this->cont < this->m ){

            int init = hf(k);
            hash->moveTo(init);
            perm->moveStart();
            int offset = 0;
            int curr = init;

            while(hash->getValue().key() != this->nullK && hash->getValue().value() != this->nullV){

                offset = perm->getValue();
                curr = (init + offset) % this->m;
                perm->next();
                hash->moveTo(curr);
            }
    
            KV<Key, T> entry(k, v);
            hash->remove();
            hash->insert(entry);
            this->cont++;
        }
        else
            cout << "already full!" << endl;
    }

    T remove(Key k){

        int pos = this->find(k);

        if( pos != -1 ){

            hash->moveTo(pos);
            T aux;
            KV<Key, T> nullKV(nullK, nullV);

            aux = this->hash->remove().value();
            
            this->hash->insert(nullKV);
            this->cont--;
            
            return aux;
        }
        else
            cout << "not in dict" << endl;
    }

    int size(){

        return this->cont;
    }

    List<Key> getKeys(){

        List<Key> keys;
        int n = 0;
        hash->moveStart();

        for(int i = 0; i < this->m && n < this->cont; i++){

            if(hash->getValue().key() != nullK && hash->getValue().value() != nullV ){

                keys.append( hash->getValue().key() );
                n++;
            }
            hash->next();
        }
        keys.printList();
        return keys;
    }

    void printKeys(){

        int n = 0;
        hash->moveStart();

        for(int i = 0; i < this->m && n < this->cont; i++){

            if(hash->getValue().key() != nullK && hash->getValue().value() != nullV ){

                n++;
                cout << hash->getValue().key() << " ";
            }
            hash->next();
        }
        cout << endl;
    }
};
#endif