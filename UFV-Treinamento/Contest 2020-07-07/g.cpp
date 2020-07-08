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
#define MAXN 200100

using namespace std;

int n;
ll a[MAXN];
ll dp[2 * MAXN];
vector<int> adj[2 * MAXN];

void dfs(int u){
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        dp[v] = dp[u] + a[v/2];
        dfs(v);
    }
}

int main(){
    optimize;

    cin >> n;
    for(int i = 2; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n; i++){
        int up = i + a[i];
        int down = i - a[i];
        adj[up <= n ? 2 * up + 1 : 0].push_back(2 * i);
        adj[down > 0 ? 2 * down  : 0].push_back(2 * i + 1);        
    }

    ms(dp, -1);
    dp[0] = 0;
    dfs(0);

    for(int i = 2; i <= n; i++)
        cout << (dp[2 * i + 1] == -1 ? -1 : dp[2 * i + 1] + i - 1) << "\n";
    
    return 0;   
}
