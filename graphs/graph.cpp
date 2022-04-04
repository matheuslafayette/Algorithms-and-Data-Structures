#ifndef GRAPH_CPP
#define GRAPH_CPP
#include "./graph.h"
#include <bits/stdc++.h>
using namespace std;

template <typename T> class graph : public Graph <T>{

    private:
        vector<vector<T>> adj;
        vector<bool> vis;
        stack<T> respTopoDfs;
        vector<T> respTopoBfs;
        vector<int> depend;
        int n;
        int e;

        void resetMark(){

            fill(this->vis.begin(), this->vis.end(), false);
        }

        void auxbfs(T origem){

            queue<T> q;

            q.push(origem);
            this->setMark(origem);

            while(!q.empty()){

                int u = q.front();
                q.pop();
                cout << u << " ";

                for(auto i = this->adj[u].begin(); i != this->adj[u].end(); i++){

                    if(this->vis[*i] == false){

                        this->vis[*i] = true;
                        q.push(*i);
                    }
                }
            } 
            cout << endl;
        }

        void auxdfs(T origem){

            this->vis[origem] = true;
            cout << origem << " ";

            for(auto i = this->adj[origem].begin(); i != this->adj[origem].end(); i++){
                
                if(this->vis[*i] == false)
                    auxdfs(*i);
            } 
        }

        void auxtopoDfs(int x){

            this->setMark(x);

            for(auto i = this->adj[x].begin(); i != this->adj[x].end(); i++)

                if(!this->getMark(*i))
                    auxtopoDfs(*i);
            
            this->respTopoDfs.push(x);
        }
        

    public:
        graph(int tam = 1000){

            this->adj.resize(tam+1);
            this->vis.resize(tam+1);
            this->depend.resize(tam+1);
            this->n = 0;
            this->e = 0;
        }

        ~graph(){

        }

        int nVert(){

            return this->n;
        }

        int nEdges(){

            return this->e;
        }

        T first(T vert){

            if( !this->adj[vert].empty() )
                return this->adj[vert][0];
            
            else
                return NULL;
        }

        T next(T vert, T prox){

            auto i = find( this->adj[vert].begin(), this->adj[vert].end(), prox );

            if( i != this->adj[vert].end() && ++i != this->adj[vert].end() )
                return *i;

            return NULL;
        }

        void setEdge(T a, T b){
            
            if(this->adj[a].empty())
                this->n++;
            this->e++;

            this->adj[a].push_back(b);
            this->depend[b]++;
        }

        void delEgde(T a, T b){

            for(int i = 0; i < this->adj[a].size(); i++){

                if(this->adj[a][i] == b){
                    
                    this->adj[a].erase( this->adj[a].begin() + i );

                    this->n--;
                    if( this->adj[a].empty() )
                        this->e--;

                    break;
                }
            }
        }

        bool isEdge(T a, T b){

            if( find( this->adj[a].begin(), this->adj[a].end(), b) != this->adj[a].end() )
                return true;
            
            return false;
        }

        void setMark(T a){

            this->vis[a] = true;
        }

        int getMark(T a){

            return this->vis[a];
        }

        void bfs(T origem){

            this->auxbfs(origem);
            this->resetMark();
        }

        void dfs(T origem){

            this->auxdfs(origem);
            cout << endl;
            this->resetMark();
        }

        void topoDfs(int x){

            this->auxtopoDfs(x);
            
            T aux;
            while(!this->respTopoDfs.empty()){

                aux = this->respTopoDfs.top();
                this->respTopoDfs.pop();
                cout << aux << " ";
            }
            cout << endl;
        }

        void topoBfs(){

            queue<int> elem;

            for(int i = 0; i < this->tam; i++)
                if(this->depend[i] == 0)
                    elem.push(i);
            
            while(!elem.empty()){

                int v = elem.front();
                elem.pop();
                respTopoBfs.push_back(v);
                cout << v << endl;

                for(auto i = adj[v].begin(); i != adj[v].end(); i++)
                    if(--depend[*i] == 0)
                        elem.push(*i);
            }
        }
};
#endif