#include <bits/stdc++.h>
#include "linkedList.h"
#define endl '\n'
using namespace std;

int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int TAM, tam, value;
    string str;
    List<int> l;
    l.insert(1);
    l.clear();
    l.insert(2);
    l.printList();

    // cin >> TAM;

    // while(TAM--){

    //     List<int> l;
    //     cin >> tam;
    //     while(tam--){
 
    //         cin >> str;           

    //         if(str == "insert"){

    //             cin >> value;
    //             l.insert(value);
    //         }

    //         else if(str == "remove")
    //             l.remove();
              
    //         else if(str == "count"){

    //             cin >> value;
    //             cout << l.equals(value) << endl;        
    //         }

    //         else if(str == "prev")
    //             l.prev();
            
    //         else if(str == "next")
    //             l.next(); 
    //     }
    // }

    return 0;
}