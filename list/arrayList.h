#ifndef _LISTA_H
#define _LISTA_H

template < typename T > class List {

    private:
        int maxSize;
        int listSize;
        int curr;
        T *list;

    public:
        List();
        ~List();
        void clear();
        void insert(T value);
        void append(T value);
        T remove();
        void moveStart();
        void moveEnd();
        void prev();
        void next();
        int size();
        int currPos();
        void moveTo(int pos);
        T getValue();
        int equals(T value);
        void printList();
};
#include "arrayList.cpp"
#endif