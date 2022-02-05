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

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis){
    
    vis[u] = true;

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(!vis[v]){
            dfs(v, adj, vis);
        }
    }
}

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    if(n - 1 != m){
        cout << "NO" << "\n";
        return 0;
    }

    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    
    dfs(0, adj, vis);

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cout << "NO" << "\n";
            return 0;
        }
    }

    cout << "YES" << "\n";

    return 0;   
}
