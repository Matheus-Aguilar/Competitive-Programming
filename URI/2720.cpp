#include<bits/stdc++.h>

using namespace std;

struct Gift{
    int i, h, w, l;
    bool operator<(const Gift &g){
        if(h * w * l != g.w * g.h * g.l)
            return h * w * l < g.w * g.h * g.l;
        else
            return g.i < i;
    }
};

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k, aux;
        
        scanf("%d %d", &n, &k);
        vector<Gift>g(n);
        vector<int> id(k);

        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d", &g[i].i, &g[i].h, &g[i].w, &g[i].l);
        }

        sort(g.begin(), g.end());
        reverse(g.begin(), g.end());
        for(int i = 0; i < k; i++)
           id[i] = g[i].i;
        sort(id.begin(), id.end());
        printf("%d", id[0]);
        for(int i = 1; i < k; i++)
            printf(" %d", id[i]);
        printf("\n");
    }
}