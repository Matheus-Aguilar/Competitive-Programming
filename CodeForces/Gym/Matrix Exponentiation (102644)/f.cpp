#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 101

using namespace std;

const int dim = MAXN; //dimension of the matrix
typedef ll ntype; //type of numbers inside the matrix

int n, m;
ll adj[MAXN][MAXN];

void mult(ntype a[dim][dim], ntype b[dim][dim]){
    
    ntype c[dim][dim];
    ms(c, INF);
    
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            for(int k = 0; k < dim; k++)
                if(a[i][k] != INFLL && b[k][j] != INFLL)
                    c[i][j] = min(a[i][k] + b[k][j], c[i][j]); 
    
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            a[i][j] = c[i][j];
}

void fastExpo(ntype x[dim][dim], ll y){

    ntype r[dim][dim];
    ms(r, 0);
    
    while(y > 0){
        if(y & 1)
            mult(r, x);
        y >>= 1;
        mult(x, x);
    }

    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            x[i][j] = r[i][j];
}

ntype calc(ntype m[dim][dim], ntype f[dim]){
    
    ntype res[dim];
    ntype small = INFLL;
    
    ms(res, INF);
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            if(m[i][j] != INFLL && f[j] != INFLL)
                res[i] = min(m[i][j] + f[j], res[i]); 

    for(int i = 0; i < dim; i++)
        small = min(small, res[i]);
    
    return small;
}

ntype calc(ll k){
    
    //base cases of the recurrence, in crescent order
    ntype base[dim];

    ms(base, 0);

    //Transformation matrix
    ntype m[dim][dim];

    ms(m, INF);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            m[i][j] = adj[i][j];
            
    fastExpo(m, k);

    return calc(m, base);
}

int main(){
    optimize;

    ll k;
    cin >> n >> m >> k;
    
    ms(adj, INF);

    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        adj[v][u] = c;
    }

    ll best = calc(k);

    if(best == INFLL)
        cout << "IMPOSSIBLE" << "\n";
    else
        cout << best << "\n";

    return 0;   
}
