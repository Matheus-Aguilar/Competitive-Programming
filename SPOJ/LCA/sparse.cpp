#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>
#define MAXN 1010

using namespace std;

int log[MAXN];
int sparseTable[MAXN][MAXN];

vector<vector<int>> adj;
vector<int> depth;
vector<int> first;
vector<int> euler;

int combine(int a, int b){
    if(a == -1) return b;
    if(b == -1) return a;
    return (depth[a] < depth[b] ? a : b);
}

void build(int size){
     
}

int query(int l, int r){
    
}

void dfs(int u, int &disc){
    
    euler.push_back(u);
    first[u] = disc++;

    for(int v:adj[u]){ 
        depth[v] = depth[u] + 1;
        dfs(v, disc);
        euler.push_back(u);
        ++disc;
    }
}

void precalc(int root, int n){
    
    int disc;
    
    euler.clear();
    depth.resize(n);
    first.resize(n);

    depth[root] = disc = 0;
    dfs(root, disc);

    build(euler.size());
}

int lca(int u, int v){
    if(first[u] > first[v])
        swap(u, v);
    return query(first[u], first[v]);
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

