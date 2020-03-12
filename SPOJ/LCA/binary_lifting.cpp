#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>
#define MAXN 1010

using namespace std;

int logSize;

vector<vector<int>> adj;
vector<int> in;
vector<int> out;
vector<vector<int>> up;

void dfs(int u, int prev, int &disc){
    
    in[u] = ++disc;

    up[u][0] = prev;
   
    for(int i = 1; i <= logSize; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for(int v:adj[u]){
        if(v != prev)
            dfs(v, u, disc);
    }

    out[u] = ++disc;
}

bool isLCA(int u, int v){
    return in[u] <= in[v] && out[u] >= out[v]; 
}

int findLCA(int u, int v){
    if(isLCA(u, v)) return u;
    if(isLCA(v, u)) return v;
    for(int i = logSize; i >= 0; i--){
        if(!isLCA(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}

void precalc(int root, int n){

    logSize = ceil(log2(n));
    in.resize(n);
    out.resize(n);
    up.assign(n, vector<int>(logSize + 1));
    int disc = 0;

    dfs(root, root, disc);
}

int lca(int u, int v){
    return findLCA(u, v);
}

int main(){
    optimize;

    int tests;
    cin >> tests;
    for(int t = 1; t <= tests; t++){
        int n;
        
        cin >> n;

        adj.resize(n);
        
        vector<bool> isRoot(n, true);

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            while(m--){
                int v;
                cin >> v;
                adj[i].push_back(v - 1);
                isRoot[v - 1] = false;
            }
        }

        int root = find(isRoot.begin(), isRoot.end(), true) - isRoot.begin();

        precalc(root, n);
        
        int q;
        cin >> q;

        cout << "Case " << t << ":\n";

        while(q--){
            int u, v;
            cin >> u >> v;
            cout << lca(u - 1, v - 1) + 1 << "\n";
        }

        adj.clear();
    }

    return 0;   
}

