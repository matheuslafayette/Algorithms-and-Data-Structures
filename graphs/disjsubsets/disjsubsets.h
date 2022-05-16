#ifndef _DISJSUBSETS_H
#define _DISJSUBSETS_H

class Ds{

    public:
        Ds() {};
        ~Ds() {};
        int find(int);
        void join(int, int);
};
#include "./disjsubsets.cpp"
#endif