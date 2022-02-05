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

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, int &cv, int &ce){
    
    vis[u] = true;
    
    cv++;
    ce += adj[u].size();

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(!vis[v]){
            dfs(v, adj, vis, cv, ce);
        }
    }
}

int main(){
    optimize;

    int n;
    
    while(cin >> n){

        if(n == -1)
            break;

        vector<int> x0(n), y0(n), x1(n), y1(n);
        vector<pii> p;

        for(int i = 0; i < n; i++){
            cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
            
            p.emplace_back(x0[i], y0[i]);
            p.emplace_back(x1[i], y1[i]);
        }

        sort(all(p));
        p.resize(unique(all(p)) - p.begin());

        vector<vector<int>> adj(p.size());
        vector<bool> vis(p.size(), false);

        for(int i = 0; i < n; i++){
            int u = lower_bound(all(p), pii(x0[i], y0[i])) - p.begin();
            int v = lower_bound(all(p), pii(x1[i], y1[i])) - p.begin();

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        for(int i = 0; i < p.size(); i++){
            if(!vis[i]){
                int cv = 0, ce = 0;

                dfs(i, adj, vis, cv, ce);

                ce /= 2;

                ans += ce - cv + 1;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
