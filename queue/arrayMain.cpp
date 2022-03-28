#include <iostream>
#include "arrayQueue.h"
#define endl '\n'
using namespace std;

int main(){

    //cin.tie(nullptr);
    //ios_base::sync_with_stdio(false);

    Queue<int> s(3);

    s.enqueue(1);
    cout << s.size() << endl;
    s.enqueue(2);
    cout << s.size() << endl;
    s.dequeue();
    cout << s.size() << endl;
    s.enqueue(3);
    cout << s.size() << endl;
    s.enqueue(4);
    cout << s.size() << endl;
    s.dequeue();
    cout << s.size() << endl;
    s.dequeue();
    cout << s.size() << endl;
    s.dequeue();
    cout << s.size() << endl;
    s.dequeue();
    cout << s.size() << endl;

    return 0;
}