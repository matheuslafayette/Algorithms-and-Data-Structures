#include <iostream>
#include "arrayQueue.h"
#define endl '\n'
using namespace std;

int main(){

    //cin.tie(nullptr);
    //ios_base::sync_with_stdio(false);

    Queue<int> s(3);
    s.enqueue(2);
    s.enqueue(2);
    s.enqueue(2);
    s.clear();
    cout << s.size() << endl;

    // s.enqueue(1);
    // cout << "TAM = " << s.size() << " -- TOP = " << s.frontValue() << endl;
    // s.enqueue(2);
    // cout << "TAM = " << s.size() << " -- TOP = " << s.frontValue() << endl;
    // s.dequeue();
    // cout << "TAM = " << s.size() << " -- TOP = " << s.frontValue() << endl;
    // s.enqueue(3);
    // cout << "TAM = " << s.size() << " -- TOP = " << s.frontValue() << endl;
    // s.enqueue(4);
    // cout << "TAM = " << s.size() << " -- TOP = " << s.frontValue() << endl;
    // s.dequeue();
    // cout << "TAM = " << s.size() << " -- TOP = " << s.frontValue() << endl;
    // s.dequeue();
    // cout << "TAM = " << s.size() << " -- TOP = " << s.frontValue() << endl;
    // s.dequeue();
    // cout << "TAM = " << s.size() << " -- TOP = " << s.frontValue() << endl;
    // s.dequeue();
    // cout << "TAM = " << s.size() << " -- TOP = " << s.frontValue() << endl;

    return 0;
}