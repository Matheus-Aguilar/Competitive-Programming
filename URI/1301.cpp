#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

int t[4 * MAX];
int a[MAX];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = (a[tl] > 0 ? 1 : (a[tl] < 0 ? -1 : 0));
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] * t[v*2+1];
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = (new_val > 0 ? 1 : (new_val < 0 ? -1 : 0));
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] * t[v*2+1];
    }
}

int prod(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 1;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return prod(v*2, tl, tm, l, min(r, tm))
           * prod(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) == 2){
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        build(a, 1, 0, n - 1);
        while(k--){
            char op;
            int l, r;
            scanf("\n%c %d %d", &op, &l, &r);
            if(op == 'C'){
                update(1, 0, n - 1, l - 1, r);
            }
            else{
                int res = prod(1, 0, n - 1, l - 1, r - 1);
                if(res > 0)
                    printf("+");
                else if(res < 0)
                    printf("-");
                else
                    printf("0");
            }
        }
        printf("\n");
    }
}