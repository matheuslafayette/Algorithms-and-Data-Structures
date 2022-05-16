#include "./../graph.h"
#define endl '\n'
typedef long long ll;

int main(){

    wgraph<int> a(6);

    a.setEdge(0, 1, 10);
    a.setEdge(1, 0, 10);

    a.setEdge(0, 3, 20);
    a.setEdge(3, 0, 20);

    a.setEdge(0, 2, 3);
    a.setEdge(2, 0, 3);

    a.setEdge(1, 3, 5);
    a.setEdge(3, 1, 5);

    a.setEdge(1, 2, 2);
    a.setEdge(2, 1, 2);
    
    a.setEdge(2, 4, 15);
    a.setEdge(4, 2, 15);

    a.setEdge(4, 3, 11);
    a.setEdge(3, 4, 11);
    //a.dijkstra(0);
    //a.floyd();
    a.prim();
    a.kruskal();
    
    return 0; 
}