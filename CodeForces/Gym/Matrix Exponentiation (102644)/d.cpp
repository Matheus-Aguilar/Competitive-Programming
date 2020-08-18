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
bool adj[MAXN][MAXN];

void mult(ntype a[dim][dim], ntype b[dim][dim]){
    
    ntype c[dim][dim];
    ms(c, 0);
    
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            for(int k = 0; k < dim; k++)
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) mod) mod; 
    
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            a[i][j] = c[i][j];
}

void fastExpo(ntype x[dim][dim], ll y){

    ntype r[dim][dim];

    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            r[i][j] = (i == j);
    
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
    ll sum = 0;

    ms(res, 0);
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            res[i] = (res[i] + (m[i][j] * f[j]) mod) mod;

    for(int i = 0; i < dim; i++)
        sum = (sum + res[i]) mod;
    
    return sum;
}

ntype calc(ll k){
    
    //base cases of the recurrence, in crescent order
    ntype base[dim];

    ms(base, 0);
    for(int i = 0; i < n; i++)
        base[i] = 1;

    //Transformation matrix
    ntype m[dim][dim];

    ms(m, 0);
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
    
    while(m--){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[v][u] = true;
    }

    cout << calc(k) << "\n";

    return 0;   
}
