#include<bits/stdc++.h>

using namespace std;

int grundy1(int n){
    if(!n) return 0;

    if(n % 2){
        if(grundy1(n - 1) == 0)
            return 1;
        else
            return 0;
    }
    else{
        if(grundy1(n - 1) == 1)
            return 2;
        else
            return 1;
    }
}

int grundy2(int n){
    if(!n) return 0;

    if(n % 2){
        if(grundy2(n - 1) == 0)
            return 1;
        else
            return 0;
    }
    else{
        int res = 0;
        if(grundy2(n - 1) == 0)
            res = 1;
        if(res == 0 && grundy2(n/2) == 0)
            res = 1;
        if(res == 1 && grundy2(n/2) == 1)
            res = 2;
        if(grundy2(n/2) == 0 && grundy2(n - 1) == 1)
            res = 2;
        return res;
    }
}

int main(){
    for(int i = 0; i < 50; i++)
        cout << i << " " << grundy1(i) << " " << grundy2(i) << endl;
}