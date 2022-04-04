#ifndef _GRAPH_H
#define _GRAPH_H

template <typename T> class Graph{

    public:
        Graph() {};
        ~Graph() {};
        int nVert();
        int nEdges();
        T first(T);
        T next(T, T);
        void setEdge(T, T);
        void delEdge(T, T);
        bool isEdge(T, T);
        int weight(T, T);
        void setMark(T);
        int getMark(T, T);
        void bfs(T);
        void dfs(T);
        void topoDfs(T);
        void topoBfs(T);
};
#include "./graph.cpp"
#endif