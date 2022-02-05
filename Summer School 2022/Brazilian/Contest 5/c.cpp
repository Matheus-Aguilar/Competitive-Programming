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

int n, parent[MAXN], height[MAXN], subtree[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], idx[MAXN], val[MAXN], bit[MAXN];
int cur_pos;

vector<vector<pii>> adj;

/*BIT*/

void update(int x, int v){

    x++;

    while(x <= n){
        bit[x] += v;
        x += (-x & x);
    }
}

ll query(int x){

    ll sum = 0;

    while(x > 0){
        sum += bit[x];
        x -= (-x & x);
    }

    return sum;
}

ll query(int l, int r){
    return query(r + 1) - query(l);
}

void build(){
    for(int i = 0; i < n; i++)
        update(pos[i], val[i]);
}

/*HLD*/

void dfs(int u) {
    
    subtree[u] = 1;
    heavy[u] = -1;

    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i].first;
        int w = adj[u][i].second;

        if(v != parent[u]){
            parent[v] = u;
            height[v] = height[u] + 1;
            val[v] = w;

            dfs(v);

            
            if(heavy[u] == -1 || subtree[heavy[u]] < subtree[v])
                heavy[u] = v;
            subtree[u] += subtree[v];
        }
    }
}

void decompose(int u, int h, int &cur) {
    
    head[u] = h, 
    idx[cur] = u;
    pos[u] = cur++;

    if(heavy[u] != -1)
        decompose(heavy[u], h, cur);

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;

        if(v != parent[u] && v != heavy[u])
            decompose(v, v, cur);
    }
}

int getDist(int u, int v){
    int dist = 0;

    while(head[u] != head[v]){
        if(height[head[u]] > height[head[v]])
            swap(u, v);
        dist += query(pos[head[v]], pos[v]);
        v = parent[head[v]];
    }

    if(height[u] > height[v])
        swap(u, v);

    dist += query(pos[u] + 1, pos[v]);

    return dist;
}

int getKth(int u, int v, int k){
    
    int auxu = u, auxv = v;
    int pu = 0, pv = 0;

    k--;

    while(head[u] != head[v]){
        if(height[head[u]] > height[head[v]])
            swap(u, v);
        pv += pos[v] - pos[head[v]] + 1;
        v = parent[head[v]];
    }

    if(height[u] > height[v])
        swap(u, v);

    pv += pos[v] - pos[u];

    u = auxu, v = auxv;
    bool add = false;

    while(head[u] != head[v]){

        if(height[head[u]] > height[head[v]]){
            swap(u, v);
            swap(pu, pv);
            add = !add;
        }

        int sz = pos[v] - pos[head[v]] + 1;

        if(add){
            if(pv + sz > k)
                return idx[pos[v] - (k - pv)];
            pv += sz;
        }
        else {
            if(pv - sz < k)
                return idx[pos[v] - (pv - k)];
            pv -= sz;
        }

        v = parent[head[v]];
    }

    if(height[u] > height[v]){
        swap(u, v);
        swap(pu, pv);
        add = !add;
    }

    if(add)
        return idx[pos[v] - (k - pv)];

    return idx[pos[v] - (pv - k)];
}

void init(int root) {

    parent[root] = -1;
    val[root] = 0;
    height[root] = 0;

    int cur = 0;

    dfs(root);
    decompose(root, root, cur);
    build();
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        cin >> n;

        adj.resize(n);

        for(int i = 0; i < n - 1; i++){
            int u, v, c;
            cin >> u >> v >> c;

            adj[u - 1].emplace_back(v - 1, c);
            adj[v - 1].emplace_back(u - 1, c);
        }

        init(0);

        string op;

        while(cin >> op){
            if(op == "DONE")
                break;
            if(op == "DIST"){
                int u, v;
                cin >> u >> v;
                cout << getDist(u - 1, v - 1) << "\n";
            }
            else{
                int u, v, k;
                cin >> u >> v >> k;
                cout << getKth(u - 1, v - 1, k) + 1 << "\n";
            }
        }

        adj.clear();
    }
    
    return 0;   
}
