#ifndef WGRAPH_CPP
#define WGRAPH_CPP
#include "./graph.h"
#include <bits/stdc++.h>
using namespace std;

template <typename T> class wgraph : public Graph <T>{

    private:
        vector<vector<pair<T, int>>> adj;
        vector<bool> vis;
        stack<pair<T,int>> respTopoDfs;
        vector<pair<T,int>> respTopoBfs;
        vector<int> depend;
        vector<int> dist;
        vector<vector<int>> alldist;
        int n;
        int e;
        int tam;

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

                    if(this->vis[(*i).first] == false){

                        this->vis[(*i).first] = true;
                        q.push((*i).first);
                    }
                }
            } 
            cout << endl;
        }

        void auxdfs(T origem){

            this->vis[origem] = true;
            cout << origem << " ";

            for(auto i = this->adj[origem].begin(); i != this->adj[origem].end(); i++){
                
                if(this->vis[(*i).first] == false)
                    auxdfs((*i).first);
            } 
        }

        void auxtopoDfs(int x){

            this->setMark(x);

            for(auto i = this->adj[x].begin(); i != this->adj[x].end(); i++)

                if(!this->getMark((*i).first))
                    auxtopoDfs((*i).first);
            
            this->respTopoDfs.push(x);
        }
        

    public:
        wgraph(int tam = 1000){

            this->adj.resize(tam+1);
            this->vis.resize(tam+1);
            this->depend.resize(tam+1);
            this->n = 0;
            this->e = 0;
            this->tam = tam;
        }

        ~wgraph(){

        }

        int nVert(){

            return this->n;
        }

        int nEdges(){

            return this->e;
        }

        T first(T vert){

            if( !this->adj[vert].empty() )
                return this->adj[vert][0].first;
            
            else
                return NULL;
        }

        // T next(T vert, T prox){

        //     auto i = find( this->adj[vert].begin(), this->adj[vert].end(), prox );

        //     if( i != this->adj[vert].end() && ++i != this->adj[vert].end() )
        //         return *i;

        //     return NULL;
        // }

        void setEdge(T a, T b, int w){
            
            if(this->adj[a].empty())
                this->n++;
            this->e++;

            this->adj[a].push_back({b, w});
            this->depend[b]++;
        }

        void delEgde(T a, T b){

            for(int i = 0; i < this->adj[a].size(); i++){

                if(this->adj[a][i].first == b){
                    
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

        bool getMark(T a){

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

        int weight(T a, T b){

            for(auto i = adj[a].begin(); i != adj[a].end(); i++){

                if((*i).first == b)
                    return (*i).second;
            }
            return 0;
        }

        void dijkstra(T source){

            this->dist.resize(tam);
            
            for(int i = 0; i < this->tam; i++)
                dist[i] = INT_MAX;
            
            resetMark();

            dist[source] = 0;

            priority_queue< pair<int, T>, vector< pair<int, T> >, greater< pair<int, T> > > pq;
            pq.push({0, source});

            while(!pq.empty()){

                int w = pq.top().first;
                int v = pq.top().second;
                pq.pop();

                if(w > dist[v])
                    continue;

                for(auto i = adj[v].begin(); i != adj[v].end(); i++){

                    T nextV = (*i).first;
                    int nextW = (*i).second;

                    if(dist[v] + nextW < dist[nextV]){

                        dist[nextV] = dist[v] + nextW;
                        pq.push({dist[nextV], nextV});
                    }
                }    
            }

            for(int i = 0; i < dist.size(); i++){

                cout << "distance of " << source << " to " << i << " = " << dist[i] << endl;
            }

        }

        void floyd(){

            this->alldist.resize(this->tam);

            for(int i = 0; i < this->tam; i++)
                for(int j = 0; j < this->tam; j++){

                    if(i == j)
                        alldist[i].push_back(0);
                    
                    else if(weight(i, j) == 0)
                        alldist[i].push_back(INT_MAX);
                    
                    else
                        alldist[i].push_back(weight(i, j));
                }
            
            for(int k = 0; k < this->tam; k++)
                for(int i = 0; i < this->tam; i++)
                    for(int j = 0; j < this->tam; j++)
                        if(alldist[i][k] != INT_MAX && alldist[k][j] != INT_MAX && alldist[i][j] > alldist[i][k] + alldist[k][j])
                            alldist[i][j] = alldist[i][k] + alldist[k][j];
            
            for(int i = 0; i < this->tam; i++)
                for(int j = 0; j < this->tam; j++)
                    if(alldist[i][j] != INT_MAX)
                        cout << "dist of " << i << " to " << j << " = " << alldist[i][j] << endl;
                    else
                        cout << "dist of " << i << " to " << j << " = " << "none" << endl;
        }
};
#endif