#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<long long int, long long int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

void dfs(int u, vector<vector<pii>> &adj, vector<pii> &parent, vector<pii> &height){
    for(pii v:adj[u]){
        if(v.first != parent[u].first){
            parent[v.first] = pii(u, v.second);
            height[v.first] = pii(height[u].first + 1, v.first);
            dfs(v.first, adj, parent, height); 
        }
    }
}

int main(){
    optimize;
    
    int n, m;
    cin >> n >> m;

    vector<pii> parent(n);
    vector<pii> height(n);
    vector<int> treasure(n);
    vector<vector<pii>> adj(n);

    for(int i = 0; i < n; i++)
        cin >> treasure[i];

    for(int i = 0; i < n - 1; i++){
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        adj[u].push_back(pii(v, c));
        adj[v].push_back(pii(u, c));
    }

    parent[0] = pii(-1, 0);
    height[0] = pii(0, 0);
    dfs(0, adj, parent, height);

    ll ans = 0;

    sort(all(height));
    reverse(all(height));

    for(int i = 0; i < n - 1; i++){
        int v = height[i].second;
        ans += 2 * parent[v].second * ((treasure[v] + m - 1)/m);
        treasure[parent[v].first] += treasure[v];
    }

    cout << ans << "\n";

    return 0;   
}
