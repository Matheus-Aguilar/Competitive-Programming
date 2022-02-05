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
#define MAXN 1010

using namespace std;

int n, m, dp[MAXN];
vector<pii> adj[MAXN];

int solve(int u){

    if(dp[u] == -1){
        dp[u] = 0;

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            
            dp[u] = max(dp[u], solve(v) + w);
        }
    }

    return dp[u];
}

int main(){
    optimize;

    ms(dp, -1);
    
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u - 1].emplace_back(v - 1, c);
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = max(ans, solve(i));
    }

    cout << ans << "\n";

    return 0;   
}
