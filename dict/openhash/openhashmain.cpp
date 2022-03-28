#include "./../dict.h"
#include <iostream>
#include <string>
using namespace std;

int hashfunc(int val){

    return val % 3;
}

int main(){

    Ldict<int, char> a(10, &hashfunc);

    cout << a.size() << endl;
    a.insert(3, 'a');
    a.insert(5, 'b');
    List<char> v;

    a.getKeys();

    return 0;
}

