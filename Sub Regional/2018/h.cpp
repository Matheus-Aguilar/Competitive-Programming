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
#define MAXP 110
#define fi first
#define se second

using namespace std;

string s, p;
vector<int> lps;

void buildKMPAutomathon(){
    lps.assign(p.size() + 1, -1);
    int i = 0, j = -1;
    while(i < p.size()){
        while(j >= 0 && p[i] != p[j])
            j = lps[j];
        lps[++i] = ++j;
    }
}

struct Node{
    pii states[MAXP];
    Node(){
        for(int i = 0; i < p.size(); i++)
            states[i] = pii(i, 0);
    }
    void update(char c){
        for(int i = 0; i < p.size(); i++){
            int j = i, q = 0;
            while(j >= 0 && p[j] != c)
                j = lps[j];
            j++;
            if(j == p.size()){
                q++;
                j = lps[j];
            }
            states[i] = pii(j, q);
        }
    }
    pii & operator[](size_t i){
        return states[i];
    }
};

Node merge(Node &a, Node &b){
    Node c;
    for(int i = 0; i < p.size(); i++)
        c[i] = pii(b[a[i].fi].fi, a[i].se + b[a[i].fi].se);
    return c;
}

struct HLD{
    vector<vector<int>> adj;
    vector<int> height;
    vector<int> head;
    vector<int> heavy;
    vector<int> parent;
    vector<char> chains;
    vector<int> pos;
    vector<Node> seg1;
    vector<Node> seg2;

    HLD(int n){
        adj.resize(n);
        height.assign(n, 0);
        head.resize(n);
        heavy.assign(n, -1);
        parent.assign(n, -1);
        chains.resize(n);
        pos.resize(n);
        seg1.resize(4 * n);
        seg2.resize(4 * n);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void init(int root){
        buildKMPAutomathon();
        dfs(root);
        decompose();
        buildTree(1, 0, adj.size() - 1);
    }
    int dfs(int u){
        int subtree_size = 1;
        int max_child_size = 0;
        for(int v:adj[u]){
            if(parent[u] != v){
                height[v] = height[u] + 1;
                parent[v] = u;
                int child_size = dfs(v);
                if(max_child_size < child_size){
                    max_child_size = child_size;
                    heavy[u] = v;
                }
                subtree_size += child_size;
            }
        }
        return subtree_size;
    }
    void decompose(){
        int cont = 0;
        for(int i = 0; i < adj.size(); i++){
            if(parent[i] == -1 || heavy[parent[i]] != i){
                head[i] = i;
                pos[i] = cont;
                chains[cont++] = s[i];
                for(int j = heavy[i]; j != -1; j = heavy[j]){
                    head[j] = i;
                    pos[j] = cont;
                    chains[cont++] = s[j];
                }
            }
        }
    }
    void buildTree(int node, int start, int end){
        if(start == end){
            seg1[node].update(chains[start]);
            seg2[node].update(chains[start]);
        }
        else{
            int middle = start + (end - start)/2;
            buildTree(2 * node, start, middle);
            buildTree(2 * node + 1, middle + 1, end);
            seg1[node] = merge(seg1[2 * node], seg1[2 * node + 1]);
            seg2[node] = merge(seg2[2 * node + 1], seg2[2 * node]);
        }
    }
    void updateTree(int node, int start, int end, int i, char c){
        if(start == end){
            seg1[node].update(c);
            seg2[node].update(c);
        }
        else{
            int middle = start + (end - start)/2;
            if(i <= middle)
                updateTree(2 * node, start, middle, i, c);
            else
                updateTree(2 * node + 1, middle + 1, end, i, c);
            seg1[node] = merge(seg1[2 * node], seg1[2 * node + 1]);
            seg2[node] = merge(seg2[2 * node + 1], seg2[2 * node]);
        }
    }
    pii queryTree(int node, int start, int end, int l, int r, bool inv, pii st){
        if(l > r)
            return st;
        if(l == start && r == end){
            if(!inv)
                return pii(seg1[node][st.fi].fi, seg1[node][st.fi].se + st.se);
            else
                return pii(seg2[node][st.fi].fi, seg2[node][st.fi].se + st.se);
        }
        int middle = start + (end - start)/2;
        if(!inv){
            pii left = queryTree(2 * node, start, middle, l, min(middle, r), inv, st);
            pii right = queryTree(2 * node + 1, middle + 1, end, max(middle + 1, l), r, inv, left);
            return right;
        }
        else{
            pii right = queryTree(2 * node + 1, middle + 1, end, max(middle + 1, l), r, inv, st);
            pii left = queryTree(2 * node, start, middle, l, min(middle, r), inv, right);
            return left;
        }
    }
    int query(int u, int v){
        vector<int> posU;
        vector<int> posV;
        while(head[u] != head[v]){
            if(height[head[u]] > height[head[v]]){
                posU.push_back(u);
                u = parent[head[u]];
            }
            else{
                posV.push_back(v);
                v = parent[head[v]];
            }
        }

        pii st = pii(0, 0);
        for(int i = 0; i < posU.size(); i++)
            st = queryTree(1, 0, adj.size() - 1, pos[head[posU[i]]], pos[posU[i]], true, st);
        if(height[u] < height[v])
            st = queryTree(1, 0, adj.size() - 1, pos[u], pos[v], false, st);
        else
            st = queryTree(1, 0, adj.size() - 1, pos[v], pos[u], true, st);
        for(int i = posV.size() - 1; i >= 0; i--)
            st = queryTree(1, 0, adj.size() - 1, pos[head[posV[i]]], pos[posV[i]], false, st);
        return st.se;
    }
};

int main(){
    optimize;
    
    int n, q;
    cin >> n >> q >> p >> s;

    HLD hld(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        hld.addEdge(u - 1, v - 1);
    }

    hld.init(0);

    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int u, v;
            cin >> u >> v;
            cout << hld.query(u - 1, v - 1) << "\n";
        }
        else{
            int u;
            char c;
            cin >> u >> c;
            hld.updateTree(1, 0, n - 1, hld.pos[u - 1], c);
        }
    }

    return 0;   
}
