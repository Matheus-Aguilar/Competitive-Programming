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

struct LCA{
    int n, l, root;
    vector<vector<int>> adj;

    int pos = 0;
    vector<int> in, out;
    vector<vector<int>> up;

    LCA(vector<vector<int>> _adj, int _root){
        
        adj = _adj;
        root = _root;
        
        n = adj.size();
        l = ceil(log2(n));
        
        in.resize(n);
        out.resize(n);
        up.assign(n, vector<int>(l + 1));

        dfs(root, root);
    }

    void dfs(int u, int p){
        
        in[u] = ++pos;
        up[u][0] = p;

        for(int i = 1; i <= l; i++)
            up[u][i] = up[up[u][i - 1]][i - 1];

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(v != p)
                dfs(v, u);
        }

        out[u] = ++pos;
    }

    bool isAncestor(int u, int v){
        return in[u] <= in[v] && out[u] >= out[v]; 
    }

    int getLCA(int u, int v){
        if(isAncestor(u, v))
            return u;
        if(isAncestor(v, u))
            return v;
        for(int i = l; i >= 0; i--)
            if(!isAncestor(up[u][i], v))
                u = up[u][i];
        return up[u][0];
    }
};

void dfs(vector<vector<pii>> &adj, vector<int> &cost, int u, int p = -1){
    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i].first;
        int c = adj[u][i].second;

        if(v != p){
            cost[v] = cost[u] + c;
            dfs(adj, cost, v, u);
        }
    }
}

int main(){
    //optimize;
    
    int t;
    scanf("%d",  &t);

    while(t--){

        int n, q, sum = 0;
        scanf("%d", &n);

        vector<vector<int>> adj(n + 1);
        vector<vector<pii>> adj1(n + 1), adj2(n + 1);
        vector<int> cost1(n + 1, 0), cost2(n + 1, 0);

        for(int i = 0; i < n - 1; i++){ 
            int u, v, c1, c2;
            scanf("%d%d%d%d", &u, &v, &c1, &c2);
            
            adj[u].push_back(v);
            adj[v].push_back(u);

            adj1[u].emplace_back(v, c1);
            adj1[v].emplace_back(u, c2);
            adj2[v].emplace_back(u, c1);
            adj2[u].emplace_back(v, c2);

            sum += (c1 + c2);
        }

        dfs(adj1, cost1, 1);
        dfs(adj2, cost2, 1);
        LCA lca(adj, 1);

        scanf("%d", &q);

        while(q--){
            int u, v, w;

            scanf("%d%d", &u, &v);
            w = lca.getLCA(u, v);
        
            printf("%d\n", sum - cost1[u] - cost2[v] + cost1[w] + cost2[w]);
        }        
    }

    return 0;   
}
