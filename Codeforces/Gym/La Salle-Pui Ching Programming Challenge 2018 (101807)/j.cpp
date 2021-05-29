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
#define MAXN 500100

using namespace std;

int n, heavy[MAXN], height[MAXN], subtree[MAXN], par[MAXN], head[MAXN], pos[MAXN];
ll val[MAXN], bit[MAXN];

vector<pii> adj[MAXN];
pii edges[MAXN];

/*BIT functions*/

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

/*HLD functions*/

void dfs(int u){
    
    subtree[u] = 1;
    heavy[u] = -1;

    for(int i = 0; i < adj[u].size(); i++){

        int v = adj[u][i].first;
        int w = adj[u][i].second;

        if(v != par[u]){

            par[v] = u;
            height[v] = height[u] + 1;
            val[v] = w;

            dfs(v);
        
            if(heavy[u] == -1 || subtree[heavy[u]] < subtree[v])
                heavy[u] = v;

            subtree[u] += subtree[v];
        }
    }
}

void decompose(int u, int h, int &cur){

    head[u] = h;
    pos[u] = cur++;

    if(heavy[u] != -1)
        decompose(heavy[u], h, cur);

    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i].first;

        if(v != par[u] && v != heavy[u])
            decompose(v, v, cur);
    }
}

void HLD(int root){
    
    par[root] = -1;
    height[root] = 0;
    val[root] = 0;

    int cur = 0;

    dfs(root);
    decompose(root, root, cur);
    build();
}

ll updateHLD(int u, int v, int l){
    if(height[u] > height[v])
        swap(u, v);
    update(pos[v], l - val[v]);
    val[v] = l;
}

ll queryHLD(int u, int v){

    ll sum = 0;

    while(head[u] != head[v]){
        if(height[head[u]] > height[head[v]])
            swap(u, v);
        sum += query(pos[head[v]], pos[v]);
        v = par[head[v]];
    }

    if(height[u] > height[v])
        swap(u, v);

    sum += query(pos[u] + 1, pos[v]);

    return sum;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int u, v, l;
        cin >> u >> v >> l;

        adj[u - 1].emplace_back(v - 1, l);
        adj[v - 1].emplace_back(u - 1, l);

        edges[i] = pii(u - 1, v - 1);
    }

    HLD(0);

    int q;
    cin >> q;

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int u, v;
            cin >> u >> v;
            cout << (queryHLD(u - 1, v - 1) % 2 ? "WE NEED BLACK PANDA" : "JAKANDA FOREVER") << "\n";
        }
        else{
            int i, l;
            cin >> i >> l;
            updateHLD(edges[i - 1].first, edges[i - 1].second, l);
        }
    }
    
    return 0;   
}
