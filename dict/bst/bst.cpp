#ifndef BST_CPP
#define BST_CPP
#include "./../dict.h"
#include <iostream>

template <typename Key, typename T> class BSTNode{

    private:
        
    
    public:
        Key k;
        T v;
        BSTNode *left;
        BSTNode *right;
        
        BSTNode(Key key, T value){

            this->k = key;
            this->v = value;
            this->left = NULL;
            this->right = NULL;
        }
        
        BSTNode() {

            this->k = NULL;
            this->v = NULL;
            this->left = NULL;
            this->right = NULL;
        }

        ~BSTNode(){

            
        }

        Key key(){

            return this->k;
        }
        T value(){

            return this->v;
        }     
};

template <typename Key, typename T> class BST : public Dict<Key, T> {

private:

    BSTNode<Key, T> *root;
    int contnodes;

    T findhelp(BSTNode<Key, T> *bstn, Key k){

        if( bstn == NULL )
            return NULL;
        
        if( bstn->key() > k )
            return findhelp(bstn->left, k);
        
        else if( bstn->key() < k )
            return findhelp(bstn->right, k);
        
        else
            return bstn->value();
    }

    BSTNode<Key, T> *inserthelp(BSTNode <Key,T> *bstn, Key k, T v){

        if( bstn == NULL ){

            BSTNode<Key, T> *aux;
            aux = new BSTNode<Key, T>(k, v);
            return aux;
        }


        if( bstn->key() > k )
            bstn->left = inserthelp(bstn->left, k, v);

        else
            bstn->right = inserthelp(bstn->right, k, v);

        return bstn;
    }

    BSTNode<Key, T> *removehelp(BSTNode <Key,T> *bstn, Key k){

        if(bstn == NULL)
            return NULL;
        
        if(bstn->key() > k)
            bstn->left = removehelp(bstn->left, k);
        
        else if(bstn->key() < k)
            bstn->right = removehelp(bstn->right, k);
        
        else{

            BSTNode<Key, T> *aux = bstn;

            if(bstn->left == NULL){

                delete aux;
                return bstn->right;
            }
                
            
            else if(bstn->right == NULL){

                delete aux;
                return bstn->left;
            }
                
            else{

                BSTNode<Key, T> *aux = getmin(bstn->right);
                bstn->k = aux->k;
                bstn->v = aux->v;
                bstn->right = deletemin(bstn->right);
                delete aux;
            }
        }
        return bstn;
    }

    BSTNode<Key, T> *getmin(BSTNode <Key,T> *bstn){

        if(bstn->left == NULL)
            return bstn;
        
        return getmin(bstn->left);
    }

    BSTNode<Key, T> *deletemin(BSTNode <Key,T> *bstn){

        if(bstn->left == NULL)
            return bstn->right;
        
        bstn->left = deletemin(bstn->left);

        return bstn;
    }

    void clearhelp(BSTNode <Key,T> *bstn){

        if(bstn == NULL){

            return;
        }
            
        clearhelp(bstn->left);
        clearhelp(bstn->right);

        delete bstn;
    }

    void printpreorder(BSTNode <Key,T> *bstn){

        if(bstn == NULL)
            return;
        
        cout << bstn->key() << " ";
        printpreorder(bstn->left);
        printpreorder(bstn->right);
    }

    void printinorder(BSTNode <Key,T> *bstn){

        if(bstn == NULL)
            return;
        
        printinorder(bstn->left);
        cout << bstn->key() << " ";
        printinorder(bstn->right);
    }

    void printposorder(BSTNode <Key,T> *bstn){

        if(bstn == NULL)
            return;
        
        printposorder(bstn->left);
        printposorder(bstn->right);
        cout << bstn->key() << " ";
    }

    void getKeysAux(BSTNode <Key,T> *bstn, List<Key> *l){

        if(bstn == NULL)
            return;

        l->append(bstn->key());
        getKeysAux(bstn->left, l);
        getKeysAux(bstn->right, l);
    }

public:

    BST(){

        this->root = NULL;
        this->contnodes = 0;
    }

    ~BST(){

        clearhelp(this->root);
    }

    void clear(){

        clearhelp(this->root);
        this->contnodes = 0;
        this->root = NULL;
    }

    T findbst(Key k){

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