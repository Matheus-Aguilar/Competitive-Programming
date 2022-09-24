#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

long long int p, B;
long long int b[MAX];
long long int t[MAX * 4];

long long int fastexpo(long long int a, long long int n) {
  long long int ret = 1;
  long long int b = a;
  while (n) {
    if (n & 1)
      ret = (ret * b) % p; // if(n==odd)
    b = (b * b) % p;
    n >>= 1; // n/=2
  }
  return (long long int)ret;
}

void build(long long int v, long long int tl, long long int tr) {
    if (tl == tr) {
        t[v] = 0;
    } else {
        long long int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = (t[v*2] + t[v*2+1]) % p;
    }
}

void update(long long int v, long long int tl, long long int tr, long long int pos, long long int new_val) {
    if (tl == tr) {
        t[v] = (new_val % p);
    } else {
        long long int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = (t[v*2] * b[tr - tm] + t[v*2+1]) % p;
    }
}

long long int hashy(long long int v, long long int tl, long long int tr, long long int l, long long int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    long long int tm = (tl + tr) / 2;
    return (hashy(v*2, tl, tm, l, min(r, tm)) * b[max(r - tm, 0ll)]
           + hashy(v*2+1, tm+1, tr, max(l, tm+1), r)) % p;
}

int main(){
    long long int l, n;
    while(scanf("%Ld%Ld%Ld%Ld", &B, &p, &l, &n) == 4){
        if(!B && !p && !l && !n) return 0;
        b[0] = 1;
        for(long long int i = 1; i <= l; i++)
            b[i] = (b[i - 1] * B) % p;
        build(1, 1, l);
        while(n--){
            char op;
            long long int a, b;
            scanf("\n%c%Ld%Ld", &op, &a, &b);
            if(op == 'E')
                update(1, 1, l, a, b);
            else
                printf("%Ld\n", hashy(1, 1, l, a, b)); //P/Q mod P = P * Q^(P - 2) mod P, se P Primo (fastexpo)
        }
        printf("-\n");
    }
}