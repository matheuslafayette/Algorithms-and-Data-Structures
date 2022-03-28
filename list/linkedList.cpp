#include "linkedList.h"
#include <iostream>
using namespace std;

template <typename T>  List<T> :: List(){

    this->curr = this->tail = this->head = new Node<T>();
    this->listSize = 0;
}

template <typename T> List<T> :: ~List(){

    while( this->head != NULL ){

        this->curr = this->head;
        this->head = this->head->next;
        delete this->curr;
    }
}

template <typename T> void List<T> :: clear(){

    while( this->head != NULL ){

        this->curr = this->head;
        this->head = this->head->next;
        delete this->curr;
    }

    this->curr = this->tail = this->head = new Node<T>();
    this->listSize = 0;
}

template <typename T> void List<T> :: insert(T number){

    this->curr->next = new Node<T>(number, this->curr->next);

    if(this->tail == this->curr)
        this->tail = this->curr->next;

    this->listSize++;
}

template <typename T> void List<T> :: append(T number){

    this->tail->next = new Node<T>(number, NULL);
    this->tail = this->tail->next;

    this->listSize++;
}

template <typename T> T List<T> :: remove(){

    
    if(this->curr->next == NULL){

        cout << "ERROR" << endl;
        exit(1);
    }
        
    else{

        T auxValue = this->curr->next->value;
        Node<T> *aux = curr->next;

        if(this->tail == this->curr->next)
            this->tail = this->curr;

        this->curr->next = this->curr->next->next;
        delete aux;

        this->listSize--;

        return auxValue;
    }
}

template <typename T> void List<T> :: moveStart(){

    this->curr = this->head;
}

template <typename T> void List<T> :: moveEnd(){

    this->curr = this->tail;
}

template <typename T> void List<T> :: prev(){

    if (this->curr != this->head){

        Node<T> *aux = this->head;
        while(aux->next != curr)
            aux = aux->next;
        
        curr = aux;
    }
}

template <typename T> void List<T> :: next(){

    if( this->curr->next != this->tail )
        this->curr = this->curr->next;
}

template <typename T> int List<T> :: size(){

    return this->listSize;
}

template <typename T> int List<T> :: currPos(){

    Node<T> *aux = this->head;
    int i;
    for(i = 0; aux != this->curr; i++)
        aux = aux->next;

    return i;
}

template <typename T> void List<T> :: moveTo(int pos){

    if( pos >= 0 && pos < listSize ){

        this->curr = this->head;
        for(int i = 0; i < pos; i++)
            this->curr = this->curr->next;
    }
}

template <typename T> T List<T> :: getValue(){

    if( this->curr->next != NULL)
        return this->curr->next->value;
    
    cout << "error to get value" << endl;
    exit(1);
}

template <typename T> int List<T> :: equals(T number){

    int cont = 0;

    Node<T> *aux = this->head;
    while(aux->next != NULL){

        if(aux->next->value == number)
            cont++;
        
        aux = aux->next;
    }
    return cont;
}

template <typename T> bool List<T> :: find(T number){

    Node<T> *aux = this->head;
    while(aux != NULL){

        if(aux->value == number)
            return true;

        aux = aux->next;
    }
    return false;
}

template <typename T> void List<T> :: printList(){

    Node<T> *aux = this->head;

    while(aux->next != NULL){

        cout << aux->next->value << " ";
        aux = aux->next;
    }
    cout << endl;
}