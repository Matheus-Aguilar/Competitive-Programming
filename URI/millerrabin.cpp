#include<bits/stdc++.h>

using namespace std;

long long int expMod(long long int x, long long int i, long long int n){
    
    long long int res = 1;
    
    x %= n;
    
    while(i > 0){
        if(i & 1){
            res *= x;
            res %= n;
        }
        i >>= 1;
        x *= x;
        x %= n;
    }
    return res;
}

bool MillerRabin(long long int n, long long int k){
    
    if(n == 2 || n == 3) return true;
    if(!(n & 1)) return false;

    long long int d = n - 1;
    long long int s = 0;
    while(!(d & 1)){ 
        d >>= 1;
        ++s;
    }
    while(k--){
        long long int a = rand() % (n - 3) + 2;
        long long int x = expMod(a, d, n);
        bool composite = true;
        if(x == 1 || x == n - 1) continue;
        for(long long int r = 1; r < s - 1; r++){
            x = ((x % n) * (x % n)) % n;
            if(x == 1) return false;
            if(x == n - 1){
                composite = false;
                break;
            }
        }
        if(composite) return false;
    }
    return true;
}

int main(){
    srand(time(NULL));
    long long int t, n;
    cin >> t;
    while(t--){
        scanf("%lli", &n);
        cout << (MillerRabin(n, 1000)?"Prime\n":"Not Prime\n");
    }
}