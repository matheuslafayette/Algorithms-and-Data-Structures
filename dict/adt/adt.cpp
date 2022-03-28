#ifndef ADT_CPP
#define ADT_CPP
#include "./../dict.h"
#include <iostream>

template <typename Key, typename T> class ADTNode{

    private:
        
    
    public:
        Key k;
        T v;
        int height;
        ADTNode *left;
        ADTNode *right;
        
        ADTNode(Key key, T value){

            this->k = key;
            this->v = value;
            this->left = NULL;
            this->right = NULL;
            this->height = 0;
        }
        
        ADTNode() {

            this->k = NULL;
            this->v = NULL;
            this->left = NULL;
            this->right = NULL;
            this->height = 0;
        }

        ~ADTNode(){

            
        }

        Key key(){

            return this->k;
        }
        T value(){

            return this->v;
        }     
};

template <typename Key, typename T> class ADT : public Dict<Key, T> {

private:

    ADTNode<Key, T> *root;
    int contnodes;

    T findhelp(ADTNode<Key, T> *bstn, Key k){

        if( bstn == NULL )
            return NULL;
        
        if( bstn->key() > k )
            return findhelp(bstn->left, k);
        
        else if( bstn->key() < k )
            return findhelp(bstn->right, k);
        
        else
            return bstn->value();
    }

    int h(ADTNode <Key,T> *bstn){

        if(bstn == NULL)
            return -1;
        
        return bstn->height;
    }

    int getbalance(ADTNode <Key,T> *bstn){

        if(bstn == NULL)
            return 0;
        
        return h(bstn->left) - h(bstn->right);
    }

    ADTNode<Key, T> *inserthelp(ADTNode <Key,T> *bstn, Key k, T v){

        if( bstn == NULL ){

            ADTNode<Key, T> *aux;
            aux = new ADTNode<Key, T>(k, v);
            return aux;
        }

        if( bstn->key() > k )
            bstn->left = inserthelp(bstn->left, k, v);

        else
            bstn->right = inserthelp(bstn->right, k, v);

        bstn->height = 1 + max(h(bstn->right), h(bstn->left));
        int balance = getbalance(bstn);

        if(balance < -1 && k >= bstn->right->key())
            return leftRotate(bstn);
        
        else if(balance > 1 && k < bstn->left->key())
            return rightRotate(bstn);
        
        else if(balance < -1){

            bstn->right = rightRotate(bstn->right);
            return leftRotate(bstn);
        }
        else if(balance > 1){

            bstn->left = leftRotate(bstn->left);
            return rightRotate(bstn);
        }
        
        return bstn;
    }

    ADTNode<Key, T> *removehelp(ADTNode <Key,T> *bstn, Key k){

        if(bstn == NULL)
            return NULL;
        
        if(bstn->key() > k)
            bstn->left = removehelp(bstn->left, k);
        
        else if(bstn->key() < k)
            bstn->right = removehelp(bstn->right, k);
        
        else{

            ADTNode<Key, T> *aux = bstn;

            if(bstn->left == NULL){

                delete aux;
                return bstn->right;
            }
                
            
            else if(bstn->right == NULL){

                delete aux;
                return bstn->left;
            }
                
            else{

                ADTNode<Key, T> *aux = getmin(bstn->right);
                bstn->k = aux->k;
                bstn->v = aux->v;
                bstn->right = deletemin(bstn->right);
                delete aux;
            }
        }
        return bstn;
    }

    ADTNode<Key, T> *getmin(ADTNode <Key,T> *bstn){

        if(bstn->left == NULL)
            return bstn;
        
        return getmin(bstn->left);
    }

    ADTNode<Key, T> *deletemin(ADTNode <Key,T> *bstn){

        if(bstn->left == NULL)
            return bstn->right;
        
        bstn->left = deletemin(bstn->left);

        return bstn;
    }

    void clearhelp(ADTNode <Key,T> *bstn){

        if(bstn == NULL){

            return;
        }
            
        clearhelp(bstn->left);
        clearhelp(bstn->right);

        delete bstn;
    }

    void printpreorder(ADTNode <Key,T> *bstn){

        if(bstn == NULL)
            return;
        
        cout << bstn->key() << " ";
        printpreorder(bstn->left);
        printpreorder(bstn->right);
    }

    void printinorder(ADTNode <Key,T> *bstn){

        if(bstn == NULL)
            return;
        
        printinorder(bstn->left);
        cout << bstn->key() << " ";
        printinorder(bstn->right);
    }

    void printposorder(ADTNode <Key,T> *bstn){

        if(bstn == NULL)
            return;
        
        printposorder(bstn->left);
        printposorder(bstn->right);
        cout << bstn->key() << " ";
    }

    void getKeysAux(ADTNode <Key,T> *bstn, List<Key> *l){

        if(bstn == NULL)
            return;

        l->append(bstn->key());
        getKeysAux(bstn->left, l);
        getKeysAux(bstn->right, l);
    }

    ADTNode<Key, T> *rightRotate(ADTNode <Key,T> *bstn){

        ADTNode<Key, T> *l = bstn->left;
        ADTNode<Key, T> *lr = l->right;

        l->right = bstn;
        bstn->left = lr;

        bstn->height = 1 + max(h(bstn->left), h(bstn->right));
        l->height = 1 + max(h(l->left), h(l->right));

        return l;
    }

    ADTNode<Key, T> *leftRotate(ADTNode <Key,T> *bstn){

        ADTNode<Key, T> *r = bstn->right;
        ADTNode<Key, T> *rl = r->left;

        r->left = bstn;
        bstn->right = rl;

        bstn->height = 1 + max(h(bstn->left), h(bstn->right));
        r->height = 1 + max(h(r->left), h(r->right));

        return r;
    }

public:

    ADT(){

        this->root = NULL;
        this->contnodes = 0;
    }

    ~ADT(){

        clearhelp(this->root);
    }

    void clear(){

        clearhelp(this->root);
        this->contnodes = 0;
        this->root = NULL;
    }

    T findadt(Key k){

        return (findhelp(this->root, k));
    }

    void insert(Key k, T v){

        this->root = inserthelp(this->root, k, v);
        this->contnodes++;
    }

    T remove(Key k){

        T aux = findhelp(this->root, k);
        if( aux != NULL){

            this->root = removehelp(this->root, k);
            this->contnodes--;
        }

        return aux;
    }

    int size(){

        return this->contnodes;
    }

    void printPreOrder(){

        printpreorder(this->root);
        cout << endl;
    }

    void printInOrder(){

        printinorder(this->root);
        cout << endl;
    }

    void printPosOrder(){

        printposorder(this->root);
        cout << endl;
    }

    List<Key> getKeys(){

        List<Key> l;
        getKeysAux(this->root, &l);
        return l;
    }

};
#endif