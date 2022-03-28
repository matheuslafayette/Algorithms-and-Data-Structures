#include <iostream>
#include "linkedStack.h"
#define endl '\n'
using namespace std;

int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int TAM, tam, value;
    string str;
    cin >> TAM;

    while(TAM--){

        Stack<int> s;
        cin >> str;
        while(str != "end"){
 
            cin >> value;
            if(str == "push")
                s.push(value);                
            
            else if(str == "pop"){

                int sum = 0;
                while(value--){

                    sum += s.pop();
                }
                cout << sum << endl;
            }

            cin >> str; 
        }
    }

    return 0;
}