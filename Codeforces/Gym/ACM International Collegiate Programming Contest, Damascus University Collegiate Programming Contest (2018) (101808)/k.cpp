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
#define MAXN 100100

using namespace std;

int n, q, tin[MAXN], tout[MAXN], timer = 0, up[MAXN][20];
vector<pii> adj[MAXN];
int uc, vc, wc;
ll sum[MAXN];

struct UnionFind{
    vector<int> par, sz;

    UnionFind(int x){
        par.assign(x, -1);
        sz.assign(x, 1);
    }

    void merge(int x, int y){
        
        int px = find(x);
        int py = find(y);

        if(px != py){
            if(sz[px] > sz[py])
                swap(px, py);
            par[px] = py;
            sz[py] += sz[px];
        }
    }

    int find(int x){
        if(par[x] == -1)
            return x;
        par[x] = find(par[x]);
        return par[x];
    }
};

void dfs(int u, int p){

    tin[u] = ++timer;
    up[u][0] = p;

    for(int i = 1; i < 20; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        int w = adj[u][i].second;

        if(v != p){
            sum[v] = sum[u] + w;
            dfs(v, u);
        }
    }

    tout[u] = ++timer;
}

bool isAncestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if(isAncestor(u, v))
        return u;
    if(isAncestor(v, u))
        return v;
    for(int i = 19; i >= 0; i--){
        if(!isAncestor(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}

ll dist(int u, int v){
    return sum[u] + sum[v] - 2 * sum[lca(u, v)];
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        
        cin >> n >> q;

        UnionFind uf(n);

        for(int i = 0; i < n; i++){
            
            int u, v, w;
            cin >> u >> v >> w;

            u--;
            v--;

            if(uf.find(u) == uf.find(v)){
                uc = u;
                vc = v;
                wc = w;
            } else {
                adj[u].emplace_back(v, w);
                adj[v].emplace_back(u, w);
                uf.merge(u, v);
            }
        }

        dfs(0, 0);

        while(q--){
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            ll ans = dist(u, v);
            ans = min(ans, dist(u, uc) + dist(v, vc) + wc);
            ans = min(ans, dist(u, vc) + dist(v, uc) + wc);

            cout << ans << "\n";
        }
        
        for(int i = 0; i < n; i++){
            adj[i].clear();
            sum[i] = 0;
        }

        timer = 0;
    }
    
    return 0;   
}
