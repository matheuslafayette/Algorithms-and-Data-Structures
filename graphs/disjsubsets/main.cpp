#include "disjsubsets.h"

int main(){

    ds a(5);
    a.join(4, 3);
    a.join(1, 3);
    a.join(2, 0);
    cout << a.find(1) << endl;
    cout << a.find(3) << endl;
    cout << a.find(4) << endl;
    cout << a.find(2) << endl;
    cout << a.find(0) << endl;

    return 0;
}