#include "./../priority_queue.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    Heap<int, int> a;
    a.insert(5, 5);
    a.insert(3, 3);
    a.insert(1, 1);
    a.insert(7, 7);
    a.insert(4, 4);
    a.insert(2, 2);

    a.heapBottomUp();

    cout << a.find_max() << endl;

    return 0;
}

