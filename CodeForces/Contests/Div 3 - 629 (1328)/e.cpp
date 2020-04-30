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
#define MAXN 1000100

using namespace std;

int segtree[8 * MAXN];
int disc = 0;
vector<vector<int>> adj;
vector<int> height;
vector<int> first;
vector<int> euler;
vector<int> parent;
vector<bool> visit;

int combine(int a, int b){
    if(a == -1) return b;
    if(b == -1) return a;
    return (height[a] < height[b] ? a : b);
}

void build(int node, int start, int end){
    if(start == end){
        segtree[node] = euler[start];
    }
    else{
        int middle = start + (end - start)/2;
        build(2 * node, start, middle);
        build(2 * node + 1, middle + 1, end);
        segtree[node] = combine(segtree[2 * node], segtree[2 * node + 1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(l > r) return -1;
    if(l == start && r == end) return segtree[node];
    int middle = start + (end - start)/2;
    return combine(
        query(2 * node, start, middle, l, min(middle, r)), 
        query(2 * node + 1, middle + 1, end, max(l, middle + 1), r)
    );
}

void dfs(int u){
    
    visit[u] = true;
    first[u] = disc++;
    euler.push_back(u);

    for(int v:adj[u]){
        if(!visit[v]){
            height[v] = height[u] + 1;
            parent[v] = u;
            dfs(v);
            euler.push_back(u);
            disc++;
        }
    }
}

void precalc(int root, int n){
    height.resize(n);
    first.resize(n);
    parent.resize(n);
    visit.assign(n, false);

    height[root] = 0;
    parent[root] = root;

    dfs(root);
    build(1, 0, euler.size() - 1);
}

int lca(int u, int v){
    if(first[u] > first[v])
        swap(u, v);
    return query(1, 0, euler.size() - 1, first[u], first[v]);
}

int main(){
    optimize;

    int n, m;
    cin >> n >> m;
    
    adj.resize(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    precalc(0, n);
    
    while(m--){
        int k;
        cin >> k;

        bool ans = true;
        int lowest = -1;
        vector<int> vert(k);
        for(int i = 0; i < k; i++){
            cin >> vert[i];
            --vert[i];
            if(lowest == -1 || height[lowest] < height[vert[i]])
                lowest = vert[i];
        }
        for(int i = 0; i < k; i++){
            int anc = lca(lowest, vert[i]);
            if(anc != vert[i] && anc != parent[vert[i]]){
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << "\n";
    }

    return 0;   
}
