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

vector<int> sz;
vector<int> height;
vector<vector<int>> adj;
vector<int> val;

void dfs(int u, int p){
    sz[u] = 1;
    for(int v:adj[u]){
        if(v != p){
            height[v] = height[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

int main(){
    optimize;
    
    int n, k;
    cin >> n >> k;

    adj.resize(n + 1);
    height.resize(n + 1);
    sz.resize(n + 1);
    val.resize(n + 1, -INF);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    height[1] = 0;
    dfs(1, 1);

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        val[i] = height[i] - sz[i] + 1;
    }

    sort(all(val), greater<int>());
    for(int i = 0; i < k; i++){
        ans += val[i];
    }

    cout << ans << "\n";

    return 0;   
}
