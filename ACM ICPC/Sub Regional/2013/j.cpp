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
#define MAXN 110000

using namespace std;

struct UnionFind{
    vector<int> parent;
    UnionFind(int n){
        parent.resize(n);
        iota(all(parent), 0);
    }
    int find(int a){
        if(a == parent[a])
            return a;
        parent[a] = find(parent[a]);
        return parent[a];
    }
    void merge(int a, int b){
        parent[find(a)] = find(b);
    }
};

struct Edge{
    int u, v, c;
    Edge(int u_= 0, int v_ = 0, int c_ = 0) : u(u_), v(v_), c(c_){}
    bool operator<(const Edge &o){
        return c < o.c;
    }
};

struct HLD{
    int n;

    vector<int> segtree;
    vector<int> chains;
    vector<int> height;
    vector<int> head;
    vector<int> heavy;
    vector<int> pos;
    vector<int> weight;
    vector<int> parent;
    vector<vector<pii>> adj;

    HLD(vector<vector<pii>> &other, int root){
        n = other.size();
        adj = other;
        segtree.resize(4 * n);
        chains.resize(n);
        height.resize(n);
        head.resize(n);
        heavy.resize(n);
        pos.resize(n);
        weight.resize(n);
        parent.resize(n);

        height[root] = 0;
        parent[root] = root;
        weight[root] = -INF;

        dfs(root, root);
        decompose();
        build_segtree(1, 0, n - 1);
    }

    int dfs(int u, int p){
        int tree_size = 1, max_size = 0;
        heavy[u] = -1;
        
        for(pii e:adj[u]){
            int v = e.first;
            int w = e.second;
            if(v != p){
                parent[v] = u;
                height[v] = height[u] + 1;
                int subtree_size = dfs(v, u);
                if(subtree_size > max_size) max_size = subtree_size, heavy[u] = v;
                tree_size += subtree_size;
                weight[v] = w; 
            }
        }
        return tree_size;
    }

    void decompose(){
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i || heavy[parent[i]] != i){
                for(int j = i; j != -1; j = heavy[j]){
                    head[j] = i;
                    pos[j] = cur;
                    chains[cur] = weight[j];
                    cur++;
                }
            }
        }
    }

    void build_segtree(int node, int start, int end){
        if(start == end){
            segtree[node] = chains[start];
        }
        else{
            int middle = start + (end - start)/2;
            build_segtree(2 * node, start, middle);
            build_segtree(2 * node + 1, middle + 1, end);
            segtree[node] = min(segtree[2 * node], segtree[2 * node + 1]);
        }
    }

    int query_segtree(int node, int start, int end, int l, int r){
        if(l > r) return INF;
        if(l == start && r == end) return segtree[node];
        int middle = start + (end - start)/2;
        return min(
            query_segtree(2 * node, start, middle, l, min(middle, r)),
            query_segtree(2 * node + 1, middle + 1, end, max(middle + 1, l), r)
        );
    }

    int query(int u, int v){
        int ans = INF;
        while(head[u] != head[v]){
            if(height[head[u]] > height[head[v]])
                swap(u, v);
            ans = min(ans, query_segtree(1, 0, n - 1, pos[head[v]], pos[v]));
            v = parent[head[v]];
        }
        if(height[u] > height[v])
            swap(u, v);
        ans = min(ans, query_segtree(1, 0, n - 1, pos[u] + 1, pos[v]));
        return ans;
    }
};

int n, m, s;
Edge e[MAXN];
pii sd[MAXN];
int best[MAXN];
vector<vector<pii>> adj;

void kruskal(){
    UnionFind uf(n);
    sort(e, e + m);
    reverse(e, e + m);
    int cont = 0, i = 0;
    while(cont < n - 1){
        if(uf.find(e[i].u) != uf.find(e[i].v)){
            uf.merge(e[i].u, e[i].v);
            adj[e[i].u].push_back(pii(e[i].v, e[i].c));
            adj[e[i].v].push_back(pii(e[i].u, e[i].c));
            cont++;
        }
        i++;
    }
}

int main(){
    optimize;

    while(cin >> n >> m >> s){
        adj.resize(n);
        for(int i = 0; i < m; i++){
            cin >> e[i].u >> e[i].v >> e[i].c;
            e[i].u--, e[i].v--;
        }

        kruskal();
        HLD h(adj, 0);

        for(int i = 0; i < s; i++){
            int u, v;
            cin >> u >> v;
            cout << h.query(u - 1, v - 1) << "\n";
        }

        for(int i = 0; i < n; i++)
            adj[i].clear();
    }
    
    return 0;   
}
