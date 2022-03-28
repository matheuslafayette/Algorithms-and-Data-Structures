#include <iostream>
using namespace std;

int binarysearch(int *v, int l, int r, int value){

    int mid;
    while(l <= r){

        mid = (l + r)/2;

        if(v[mid] < value)
            l = mid + 1;
        else if(v[mid] > value)
            r = mid - 1;
        else
            return mid;
    }

    return -1;   
}

int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int v[10] = {2,3,6,7,9,14,17,18,25,56};

    cout << binarysearch(v, 0, 9, 9) << endl;

    return 0;
}