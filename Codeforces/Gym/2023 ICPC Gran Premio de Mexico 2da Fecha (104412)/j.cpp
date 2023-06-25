#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 100100
#define pii pair<int, int>

using namespace std;

int n, m, q, low[MAXN], tin[MAXN], timer = 0;
bool vis[MAXN], cycle[MAXN];
vector<int> adj[MAXN];
vector<pii> bridges;

struct UnionFind {
    
    vector<int> par;

    void init(int n){
        par.assign(n + 1, -1);
    }

    void merge(int x, int y){
        
        int px = find(x);
        int py = find(y);

        if(px == py)
            return;
        
        par[px] = py;
    }

    int find(int x){
        if(par[x] == -1)
            return x;
        par[x] = find(par[x]);
        return par[x];
    }

    bool sameSet(int x, int y){
        return find(x) == find(y);
    }
};

UnionFind uf;

void tarjan(int u, int p = -1){
    
    vis[u] = true;

    tin[u] = timer;
    low[u] = timer;
    timer++;

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v == p)
            continue;
        if(vis[v]){
            low[u] = min(low[u], tin[v]);
        } else {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]){
                bridges.emplace_back(u, v);
            } else {
                cycle[u] = true;
            }
        }
    }

    if(low[u] < tin[u])
        cycle[u] = true;
}

int main(){

    optimize;

    cin >> n >> m >> q;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    uf.init(n);
    tarjan(1);

    for(int i = 0; i < bridges.size(); i++){
        
        int u = bridges[i].first;
        int v = bridges[i].second;

        if(cycle[u] || cycle[v])
            continue;
        
        uf.merge(u, v);
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << (uf.sameSet(a, b) ? "YES" : "NO") << "\n";
    }

    return 0;
}