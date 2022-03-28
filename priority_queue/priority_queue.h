#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H
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
        void setkey(Key key){

            this->k = key;
        }
        void setvalue(T value){

            this->v = value;
        }
        void set(Key key, T value){

            this->k = key;
            this->v = value;
        }
        void set(KV<Key, T> s){

            this->k = s.key();
            this->v = s.value();
        }
};

template <typename Key, typename T> class priority_queue{

    public:
        priority_queue() {};//foi
        ~priority_queue() {};
        T find_max();
        T remove_max();
        void add(Key, T);
};
#include "./heap/heap.cpp"
#include "./heap/heaptopdown.cpp"
#endif