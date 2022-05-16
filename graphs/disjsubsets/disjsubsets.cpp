#ifndef _DISJSUBSETS_CPP
#define _DISJSUBSETS_CPP
#include "./disjsubsets.h"
#include <bits/stdc++.h>
using namespace std;

class ds : public Ds{

    private:
        vector<int> v;

    public:

        ds(int tam = 0){

            this->v.resize(tam);
            
            for(int i = 0; i < tam; i++)
                this->v[i] = -1;
        }

        ~ds() {}

        int find(int curr){

            if( this->v[curr] == -1 )
                return curr;
            
            this->v[curr] = find(this->v[curr]);

            return this->v[curr];
        }

        void join(int a, int b){

            int root1 = this->find(a);
            int root2 = this->find(b);

            if(root1 != root2)
                this->v[root2] = root1;
        }
};

#endif