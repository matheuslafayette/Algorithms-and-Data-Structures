#include "graph.h"
#define endl '\n'
typedef long long ll;

int main(){

    wgraph<int> a(6);

    a.setEdge(0, 1, 2);
    a.setEdge(1, 3, 2);
    a.setEdge(3, 2, 2);
    a.setEdge(1, 2, 2);
    a.setEdge(2, 4, 2);
    a.setEdge(4, 5, 2);
    a.setEdge(1, 5, 2);
    a.dijkstra(0);
    a.floyd();
    return 0; 
}