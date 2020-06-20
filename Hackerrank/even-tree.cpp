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
vector<int> height;
vector<int> subtree;

void dfs(int u, int p = -1){
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v != p){
            height[v] = height[u] + 1;
            dfs(v, u);
            subtree[u] += subtree[v];
        }
    }
}

int main(){
    optimize;

    cin >> n >> m;

    adj.resize(n);
    height.assign(n, 0);
    subtree.assign(n, 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    dfs(0);

    int cont = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            int u = i, v = adj[i][j];
            if(height[u] > height[v])
                swap(u, v);
            if((n - subtree[v]) % 2 == 0 && subtree[v] % 2 == 0)
                cont++;
        }
    }

    cout << cont/2 << "\n";

    return 0;   
}
