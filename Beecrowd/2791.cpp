#include<iostream>

using namespace std;

int main(){
    int i = 0;
    while(++i){
        int x;
        cin >> x;
        if(x){
            cout << i << endl;
            return 0;
        }
    }
}