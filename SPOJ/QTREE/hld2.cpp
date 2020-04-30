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

int n;
int chains_size;

int segtree[6 * MAXN];
int chains[MAXN];
vector<pii> adj[MAXN];
pii edges[MAXN];
int height[MAXN];
pii heavy[MAXN];
int head[MAXN];
int pos[MAXN];
int parent[MAXN];

int dfs(int u, int p){

    heavy[u] = pii(-1, -1);
    int max_size = -1, my_size = 1;

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        if(v != p){
            height[v] = height[u] + 1;
            parent[v] = u;
            int child_size = dfs(v, u);
            my_size += child_size;
            if(child_size > max_size) {
                max_size = child_size;
                heavy[u] = adj[u][i];
            }
        }
    }
    return my_size;
}

void decompose(int u, int h){
    head[u] = h;
    pos[u] = chains_size - 1;
    
    if(heavy[u].first != -1){
        chains[chains_size++] = heavy[u].second;
        decompose(heavy[u].first, h);
    }

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        int w = adj[u][i].second;

        if(v != heavy[u].first && v != parent[u]){
            chains[chains_size++] = w;
            decompose(v, v);
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
        segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
    }
}

void init(int root){
    chains_size = 0;
    
    height[root] = 0;
    parent[root] = root;

    dfs(root, root);
    decompose(root, root);
    build_segtree(1, 0, n - 2);
}

void update_segtree(int node, int start, int end, int p, int v){
    if(start == end){
        segtree[node] = v;
    }
    else{
        int middle = start + (end - start)/2;
        if(p <= middle)
            update_segtree(2 * node, start, middle, p, v);
        else
            update_segtree(2 * node + 1, middle + 1, end, p, v);
        segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
    }
}

int query_segtree(int node, int start, int end, int l, int r){
    if(l > r) 
        return -INF;
    if(l == start && r == end) 
        return segtree[node];
    int middle = start + (end - start)/2;
    return max(
        query_segtree(2 * node, start, middle, l, min(middle, r)),
        query_segtree(2 * node + 1, middle + 1, end, max(middle + 1, l), r)
    );
}

void update(int u, int v, int c){
    if(height[u] > height[v]) swap(u, v);
    update_segtree(1, 0, n - 2, pos[v], c);
}

int query(int u, int v){
    
    int ans = -INF;

    while(head[u] != head[v]){
        if(height[head[u]] > height[head[v]]) 
            swap(u, v);
        ans = max(ans, query_segtree(1, 0, n - 2, pos[head[v]], pos[v]));
        v = parent[head[v]];
    }

    if(height[u] > height[v]) 
        swap(u, v);
    ans = max(ans, query_segtree(1, 0, n - 2, pos[u] + 1, pos[v]));
    
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n - 1; i++){
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            --u, --v;
            adj[u].push_back(pii(v, c));
            adj[v].push_back(pii(u, c));
            edges[i] = pii(u, v);
        }

        init(0);

        char s[10];
		scanf("%s", s);
        while(s[0] != 'D'){
            if(s[0] == 'C'){
                int e, w;
                scanf("%d%d", &e, &w);
                update(edges[e - 1].first, edges[e - 1].second, w);
            }
            else{
                int u, v;
                scanf("%d%d", &u, &v);
                printf("%d\n", query(u - 1, v - 1));
            }
		    scanf("%s", s);
        }

        if(t) printf("\n");
        for(int i = 0; i < n; i++)
            adj[i].clear();
    }

    return 0;   
}