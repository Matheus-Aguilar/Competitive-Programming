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

struct hld{

    /*General*/
    vector<vector<int>> adj;
    vector<int> height;
    vector<int> parent;
    
    /*LCA*/
    vector<int> euler;
    vector<int> seg_euler;
    vector<int> first;
    
    /*HLD*/
    vector<vector<int>> chains;
    vector<vector<int>> seg_chains;
    vector<vector<int>> lazy_chains;
    vector<int> heavy;
    vector<int> head;
    vector<pii> pos;

    /*Precalc functions*/
    hld(vector<vector<int>> &adj_, int root, int n){
        adj = adj_;
        height.resize(n);
        parent.resize(n);
        
        first.resize(n);
        
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);

        height[root] = 0;
        parent[root] = root;
        
        dfs(root);
        
        seg_euler.resize(4 * euler.size());
        build_euler(1, 0, euler.size() - 1);
        
        add_chain();
        decompose_chains(root, root);

        for(int i = 0; i < chains.size(); i++){
            seg_chains[i].resize(4 * chains[i].size());
            lazy_chains[i].resize(4 * chains[i].size());
            build_chain(i, 1, 0, chains[i].size() - 1);
        }
    }
    
    int dfs(int u){
        first[u] = euler.size();
        euler.push_back(u);

        int tree_size = 1;
        int max_subtree = 0;

        for(int v:adj[u]){
            if(parent[u] != v){
                parent[v] = u;
                height[v] = height[u] + 1;
                
                int subtree_size = dfs(v);
                
                euler.push_back(u);
                
                if(subtree_size > max_subtree) max_subtree = subtree_size, heavy[u] = v;
                tree_size += subtree_size;
            }
        }
        return tree_size;
    }

    void add_chain(){
        chains.emplace_back();
        seg_chains.emplace_back();
        lazy_chains.emplace_back();
    }

    void decompose_chains(int u, int h){
        head[u] = h;
        pos[u] = pii(chains.size() - 1, chains.back().size());
        chains.back().push_back(u);

        //Go to the heaviest child
        if(heavy[u] != -1)
            decompose_chains(heavy[u], h);
        
        //Decompose the other children
        for(int v:adj[u]){
            if(v != parent[u] && v != heavy[u]){
                add_chain();
                decompose_chains(v, v);
            }
        }
    }

    /*LCA functions*/
    void build_euler(int node, int start, int end){
        if(start == end){
            seg_euler[node] = euler[start];
        }
        else{
            int middle = start + (end - start)/2;
            build_euler(2 * node, start, middle);
            build_euler(2 * node + 1, middle + 1, end);
            seg_euler[node] = combine_euler(
                seg_euler[2 * node], 
                seg_euler[2 * node + 1]
            );
        }
    }

    int combine_euler(int a, int b){
        if(a == -1) return b;
        if(b == -1) return a;
        return (height[a] < height[b] ? a : b);
    }

    int query_euler(int node, int start, int end, int l, int r){
        if(l > r) return -1;
        if(l == start && r == end) return seg_euler[node];
        int middle =  start + (end - start)/2;
        return combine_euler(
            query_euler(2 * node, start, middle, l, min(middle, r)),
            query_euler(2 * node + 1, middle + 1, end, max(l, middle + 1), r)
        );
    }

    int lca(int a, int b){
        if(first[a] > first[b]) swap(a, b);
        return query_euler(1, 0, euler.size() - 1, first[a], first[b]);
    }

    /*HLD functions*/
    
    //Chain functions
    void build_chain(int id, int node, int start, int end){
        lazy_chains[id][node] = -1;
        if(start == end){
            seg_chains[id][node] = 0;
        }
        else{
            int middle = start + (end - start)/2;
            build_chain(id, 2 * node, start, middle);
            build_chain(id, 2 * node + 1, middle + 1, end);
            seg_chains[id][node] = seg_chains[id][2 * node] + seg_chains[id][2 * node + 1];
        }
    }

    void push_chain(int id, int node, int start, int end){
        if(lazy_chains[id][node] != -1){
            seg_chains[id][node] = (end - start + 1) * lazy_chains[id][node];
            if(start != end){
                lazy_chains[id][2 * node] = lazy_chains[id][node];
                lazy_chains[id][2 * node + 1] = lazy_chains[id][node];
            }
            lazy_chains[id][node] = -1;
        }
    }
    void update_chain(int id, int node, int start, int end, int l, int r, int v){
        push_chain(id, node, start, end);
        if(l > r) 
            return;
        if(l == start && r == end){
            lazy_chains[id][node] = v;
            push_chain(id, node, start, end);
            return;
        }
        int middle = start + (end - start)/2;
        update_chain(id, 2 * node, start, middle, l, min(r, middle), v);
        update_chain(id, 2 * node + 1, middle + 1, end, max(l, middle + 1), r, v);
        seg_chains[id][node] = seg_chains[id][2 * node] + seg_chains[id][2 * node + 1];
    }

    int query_chain(int id, int node, int start, int end, int l, int r){
        push_chain(id, node, start, end);
        if(l > r) return 0;
        if(l == start && r == end) return seg_chains[id][node];
        int middle = start + (end - start)/2;
        return 
            query_chain(id, 2 * node, start, middle, l, min(r, middle)) +
            query_chain(id, 2 * node + 1, middle + 1, end, max(l, middle + 1), r);
    }

    //Tree functions
    void update(int a, int b, int v){
        int id, l, r, c = lca(a, b);

        while(head[c] != head[a]){
            id = pos[a].first;
            r = pos[a].second;
            update_chain(id, 1, 0, chains[id].size() - 1, 0, r, v);
            a = parent[head[a]];
        }
        
        while(head[c] != head[b]){
            id = pos[b].first;
            r = pos[b].second;
            update_chain(id, 1, 0, chains[id].size() - 1, 0, r, v);
            b = parent[head[b]];
        }

        id = pos[c].first;
        l = pos[c].second;
        r = max(pos[a].second, pos[b].second);

        update_chain(id, 1, 0, chains[id].size() - 1, l, r, v);

    }

    int query(int a, int b){
        int acu = 0, id, l, r, c = lca(a, b);

        while(head[c] != head[a]){
            id = pos[a].first;
            r = pos[a].second;
            acu += query_chain(id, 1, 0, chains[id].size() - 1, 0, r);
            a = parent[head[a]];
        }

        while(head[c] != head[b]){
            id = pos[b].first;
            r = pos[b].second;
            acu += query_chain(id, 1, 0, chains[id].size() - 1, 0, r);
            b = parent[head[b]];
        }


        id = pos[c].first;
        l = pos[c].second;
        r = max(pos[a].second, pos[b].second);

        acu += query_chain(id, 1, 0, chains[id].size() - 1, l, r);

        return acu;
    }
};

int main(){
    optimize;
    
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    hld h(adj, 0, n);

    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b, --c, --d;

        h.update(a, b, 1);
        int total = h.query(a, b);
        h.update(c, d, 0);
        int not_shared = h.query(a, b);
        h.update(a, b, 0);
        cout << total - not_shared << "\n";
    }

    return 0;   
}
