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

int n, l;

vector<pii> coord;
vector<vector<int>> adj;

map<pii, int> idx;

vector<int> dp;

int solve(int u){
    if(u == n + 1) 
        return 0;
    if(dp[u] == -1){

        dp[u] = -INF;

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            dp[u] = max(dp[u], solve(v) + 1);
        }
    }
    return dp[u];
}

int main(){
    optimize;

    cin >> n >> l;

    coord.resize(n + 2);
    adj.resize(n + 2);
    dp.assign(n + 2, -1);

    for(int i = 1; i <= n; i++){
        cin >> coord[i].first >> coord[i].second;
        idx[coord[i]] = i;
    }

    coord[0] = make_pair(0, 0);
    idx[coord[0]] = 0;

    coord[n + 1] = make_pair(l, 0);
    idx[coord[n + 1]] = n + 1;

    for(int i = 0; i <= n + 1; i++){
        for(int x = 1; x <= 5; x++){
            for(int y = x - 5; y <= (5 - x); y++){

                auto it = idx.find(make_pair(coord[i].first + x, coord[i].second + y));
                
                if(it != idx.end()){
                    adj[i].push_back(it->second);
                }
            }
        }
    }

    cout << solve(0) - 1 << "\n";

    return 0;   
}
