#include<bits/stdc++.h>

using namespace std;

int fib[40];
int calls[40];
bool done[40] = {false};

void calcFibAndCalls(int x){
    if(done[x]) return;
    calcFibAndCalls(x - 1);
    calcFibAndCalls(x - 2);
    done[x] = true;
    calls[x] = calls[x - 1] + calls[x - 2] + 2;
    fib[x] = fib[x - 1] + fib[x - 2];
}

int main(){
    
    fib[0] = 0;
    fib[1] = 1;
    calls[1] = calls[0] = 0;
    done[1] = done[0] = true;
    
    int t;
    scanf("%d", &t);
    while(t--){
        int x;
        scanf("%d", &x);
        calcFibAndCalls(x);
        printf("fib(%d) = %d calls = %d\n", x, calls[x], fib[x]);
    }
}