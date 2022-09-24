#include<bits/stdc++.h>

using namespace std;

int uni(long long int  &x, long long int  &y){
    long long int z;
    z = x | y;
    return __builtin_popcountll(z);
}

int inter(long long int  &x, long long int  &y){
    long long int z;
    z = x & y;
    return __builtin_popcountll(z);
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long int>sets(n, 0);
        for(int i = 0; i < n; i++){
            int m;
            scanf("%d", &m);
            for(int j = 0; j < m; j++){
                int e;
                scanf("%d", &e);
                sets[i] |= (1ll << e);
            }
        }

        int q;
        cin >> q;
        for(int i = 0; i < q; i++){
            int op, x, y;
            scanf("%d%d%d", &op, &x, &y);
            --x,--y;
            if(op == 1)
                printf("%d\n", inter(sets[x], sets[y]));
            else
                printf("%d\n", uni(sets[x], sets[y])); 
        }
    }
}