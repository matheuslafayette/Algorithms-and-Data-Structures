#include "./../dict.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    BST<int, char> a;
    cout << a.size() << endl;
    a.insert(5, 'a');
    cout << a.size() << endl;
    a.insert(2,'b');
    a.insert(9,'b');
    a.insert(7,'b');
    a.insert(11,'b');
    a.printInOrder();
    cout << a.size() << endl;
    cout << a.findbst(2) << endl;
    cout << a.findbst(3) << endl;
    cout << a.findbst(4) << endl;
    a.getKeys();
    cout << a.remove(9) << endl;
    cout << a.size() << endl;
    cout << a.findbst(2) << endl;
    cout << a.findbst(3) << endl;
    cout << a.remove(2) << endl;
    cout << a.size() << endl;
    cout << a.findbst(2) << endl;
    a.clear();


    return 0;
}

