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

using namespace std;

struct UnionFind{
    
    vector<int> par, sz;
    
    UnionFind(int n = 0){
        par.resize(n);
        iota(all(par), 0);
        sz.assign(n, 1);
    }
 
    void merge(int u, int v){
        
        u = find(u);
        v = find(v);
 
        if(u == v)
            return;
 
        if(sz[u] < sz[v])
            swap(u, v);
        
        par[v] = u;
        sz[u] += sz[v];
    }
 
    int find(int u){
        if(u == par[u])
            return u;
        return par[u] = find(par[u]);
    }
 
    bool sameSet(int u, int v){
        return find(u) == find(v);
    }
};

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        UnionFind uf(n + 1);
        vector<vector<int>> c(n + 1, vector<int>(n + 1));
        vector<vector<int>> d(n + 1, vector<int>(n + 1));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> c[i][j];
                d[i][c[i][j]] = j;
            }
        }

        for(int j = 2; j <= n; j++){
            for(int i = 1; i <= n; i++){
                if(!uf.sameSet(i, c[i][j])){

                    int u = c[i][j];
                    int v = i;

                    for(int k = 2; k < j; k++){
                        if(d[u][v] > d[u][c[i][k]]){
                            v = c[i][k];
                        }
                    }

                    cout << u << " " << v << "\n";
                    uf.merge(u, v);
                }
            }
        }
        cout << "\n";
    }
    
    return 0;   
}
