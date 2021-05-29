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
#define fi first
#define se second

using namespace std;

int n, m, k, A;
vector<vector<int>> adj;
vector<int> parent;
vector<vector<int>> bfsTree;

void solveTree(){
    vector<int> red;
    vector<int> black;
    vector<int> color(n + 1, 0);

    stack<int> st;
    st.push(1);
    red.push_back(1);
    color[1] = 1;

    while(!st.empty()){
        int u = st.top();
        st.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(!color[v]){
                color[v] = (color[u] == 1 ? 2 : 1);
                if(color[v] == 1)
                    red.push_back(v);
                else
                    black.push_back(v);
                st.push(v);
            }
        }
    }

    if(red.size() >= (k + 1)/2){
        cout << 1 << "\n";
        for(int i = 0; i < (k + 1)/2; i++)
            cout << red[i] << " ";
        cout << "\n";
    }
    else{
        cout << 1 << "\n";
        for(int i = 0; i < (k + 1)/2; i++)
            cout << black[i] << " ";
        cout << "\n";
    }
}

int findCycle(){
    vector<int> visit(n + 1, 0);
    stack<int> st;
    st.push(1);
    visit[1] = true;

    while(!st.empty()){
        int u = st.top();
        st.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(!visit[v]){
                visit[v] = u;
                st.push(v);
            }
            else if(visit[u] != v){
                return v;
            }
        }
    }
    return 0;
}

void buildBFSTree(int s){
    vector<bool> visit(n + 1, false);
    queue<int> q;
    q.push(s);
    visit[s] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(!visit[v]){
                visit[v] = true;
                bfsTree[u].push_back(v);
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

struct LCA{
    vector<int> euler;
    vector<int> height;
    vector<int> first;
    vector<vector<int>> sparse;
    vector<int> log;
    vector<vector<int>> adj;

    LCA(int u, vector<vector<int>> &_adj){
        adj = _adj;
        euler.assign(2 * adj.size(), 0);
        height.assign(adj.size(), INF);
        first.resize(adj.size());
        log.resize(euler.size() + 1);
        sparse.assign(euler.size() + 1, vector<int>(log2(euler.size()) + 1));

        int pos = height[u] = 0;
        eulerTour(u, u, pos);
        buildSparseTable();
    }

    void eulerTour(int u, int p, int &pos){
        first[u] = pos;
        euler[pos++] = u;

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(v != p){
                height[v] = height[u] + 1;
                eulerTour(v, u, pos);
                euler[pos++] = u;
            }
        }
    }

    int combine(int u, int v){
        return (height[u] < height[v] ? u : v);
    }

    void buildSparseTable(){
        for(int i = 0; i < euler.size(); i++)
            sparse[i][0] = euler[i];
        for(int j = 1; j < sparse[0].size(); j++)
            for(int i = 0; i + (1 << j) < sparse.size(); i++)
                sparse[i][j] = combine(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        log[1] = 0;
        for(int i = 2; i < log.size(); i++)
            log[i] = log[i/2] + 1;
    }

    int querySparseTable(int l, int r){
        int j = log[r - l + 1];
        return combine(sparse[l][j], sparse[r - (1 << j) + 1][j]);
    }

    int getLCA(int u, int v){
        if(first[u] > first[v])
            swap(u, v);
        return querySparseTable(first[u], first[v]);
    }

    int getDist(int u, int v){
        return height[u] + height[v] - 2 * height[getLCA(u, v)];
    }
};

void solve(int root, LCA &lca){

    int cycleSize = INF;
    pii cyclePair;
    vector<int> cycle, aux;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < (int)adj[i].size(); j++){
            if(parent[i] != adj[i][j] && parent[adj[i][j]] != i && lca.getLCA(i, adj[i][j]) == root){
                if(cycleSize > lca.getDist(i, adj[i][j]) + 1){
                    cycleSize = lca.getDist(i, adj[i][j]) + 1;
                    cyclePair = pii(i, adj[i][j]);
                }
            }
        }
    }

    int u = cyclePair.fi, v = cyclePair.se;
    while(parent[u] != -1){
        cycle.push_back(u);
        u = parent[u];
    }
    cycle.push_back(root);
    while(parent[v] != -1){
        aux.push_back(v);
        v = parent[v];
    }
    reverse(all(aux));
    for(int i = 0; i < aux.size(); i++)
        cycle.push_back(aux[i]);
    
    if(cycle.size() <= k){
        cout << 2 << "\n" << cycle.size() << "\n";
        for(int i = 0; i < cycle.size(); i++)
            cout << cycle[i] << " ";
        cout << "\n";
    }
    else{
        cout << 1 << "\n";
        for(int i = 0; i < (k + 1)/2; i++)
            cout << cycle[2 * i] << " ";
        cout << "\n";
    }
}

int main(){
    optimize;
    
    cin >> n >> m >> k;
    adj.resize(n + 1);
    bfsTree.resize(n + 1);
    parent.assign(n + 1, -1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(m == n - 1){
        solveTree();
    }
    else{
        int u = findCycle();
        buildBFSTree(u);
        LCA lca(u, bfsTree);
        solve(u, lca);
    }

    return 0;   
}
