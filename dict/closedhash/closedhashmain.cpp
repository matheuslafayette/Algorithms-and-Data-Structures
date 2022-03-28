#include "./../dict.h"
#include <iostream>
#include <string>
using namespace std;

int hashfunc(int val){

    int sum = 0;
    
}

int main(){

    Cdict<int, char> a(100, &hashfunc, 0, ' ');
    a.insert(14, 'a');
    a.insert(3, 'b');
    a.insert(5,'c');
    a.printKeys();
    cout << a.remove(3) << endl;
    a.printKeys();
    cout << a.remove(14) << endl;
    a.clear();
    a.printKeys();
    a.remove(5);

    return 0;
}

