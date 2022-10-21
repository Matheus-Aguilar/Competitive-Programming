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

int n, m, t, vis[MAXN][2];
vector<int> adj[MAXN], s;

void dfs(int u, int p){
    
    if(vis[u][0] == p || vis[u][1] == p)
        return;

    if(vis[u][0] == -1)
        vis[u][0] = p;
    else if(vis[u][1] == -1)
        vis[u][1] = p;
    else
        return;
    
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        dfs(v, p);
    }
}

int main(){
    optimize;

    ms(vis, -1);
    
    cin >> n >> m >> t;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(v != t)
            adj[v].push_back(u);
        else
            s.push_back(u);
    }

    for(int i = 0; i < s.size(); i++){
        dfs(s[i], s[i]);
    }

    vector<int> ans;

    for(int i = 0; i < s.size(); i++){
        if(vis[s[i]][1] == -1)
            ans.push_back(s[i]);
    }

    cout << ans.size() << "\n";

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";

    return 0;   
}
