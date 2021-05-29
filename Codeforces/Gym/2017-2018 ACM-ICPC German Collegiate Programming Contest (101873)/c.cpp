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

int n, m, T, x, t[MAXN], p[MAXN], dp[MAXN][MAXN];
vector<int> adj[MAXN];

int solve(int i, int j){
    if(j < 0)
        return INF;
    if(j == 0)
        return (i == 0 ? 0 : INF);
    if(dp[i][j] == -1){
        dp[i][j] = solve(i, j - t[i]) + p[i];
        for(int v : adj[i]){
            dp[i][j] = min(dp[i][j], solve(v, j - t[v] - T) + p[v]);
        }
    }
    return dp[i][j];
}

int main(){
    optimize;
    
    ms(dp, -1);

    cin >> x >> n >> m >> T;

    for(int i = 0; i < m; i++){
        
        int a, b;
        cin >> a >> b;

        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    for(int i = 0; i < n; i++)
        cin >> t[i] >> p[i];

    int best = solve(0, x - t[0]) + p[0];

    if(best >= INF)
        cout << "It is a trap." << "\n";
    else
        cout << best << "\n";

    return 0;   
}
