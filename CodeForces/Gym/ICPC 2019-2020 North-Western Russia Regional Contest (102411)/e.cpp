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

int n, m;
vector<vector<int>> adj;
vector<int> subtree;
vector<int> teams;

bool bfs(int s){
    queue<int> q;
    vector<int> dist(n);
    vector<bool> visit(n, false);

    q.push(s);
    dist[s] = 0;
    visit[s] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(!visit[v]){
                visit[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 0; i < m - 1; i++)
        if(dist[teams[i]] != dist[teams[i + 1]])
            return false;
    return true;
}

void dfs(int u, int p = -1){
    
    subtree[u] = 1;

    for(int v : adj[u]){
        if(v != p){
            dfs(v, u);
            subtree[u] += subtree[v];
        }
    }
}

pii getCentroid(int u, int p = -1){
    
    int maxsize = 0;
    int maxV = -1;
    bool isCentroid = true;

    for(int v : adj[u]){
        if(v != p){
            if(subtree[v] > n/2)
                isCentroid = false;
            if(subtree[v] > maxsize){
                maxsize = subtree[v];
                maxV = v;
            }
        }
    }

    if(isCentroid)
        return pii(u, maxV);

    getCentroid(maxV, u);
}

pii getCentroid(){
    dfs(0);
    return getCentroid(0);
}

int main(){
    optimize;
    
    cin >> n >> m;

    adj.resize(n);
    subtree.resize(n);
    teams.resize(m);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < m; i++){
        cin >> teams[i];
        --teams[i];
    }

    pii centroid = getCentroid();

    if(bfs(centroid.first))
        cout << "YES\n" << centroid.first + 1 << "\n";
    else if(bfs(centroid.second))
        cout << "YES\n" << centroid.second + 1 << "\n";
    else
        cout << "NO" << "\n";

    return 0;   
}
