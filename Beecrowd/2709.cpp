#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

bool prime(int n){
    if(n == 2) return true;
    if(!(n & 1) || n == 1) return false;
    for(int i = 3; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}

int main(){
    int m, n;
    while(scanf("%d", &m) == 1){
        vector<int>v(m);
        for(int i = 0; i < m; i++) scanf("%d", &v[i]);
        scanf("%d", &n);
        int total = 0;
        for(int i = m - 1; i >= 0; i -= n) total += v[i];
        if(prime(total))
            printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
        else
            printf("Bad boy! I’ll hit you.\n");
    }
}