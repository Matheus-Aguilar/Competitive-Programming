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
#define MAXN 510

using namespace std;

int n, m, k;

ll dp[MAXN][MAXN][30];
vector<pair<int, ll>> adj[MAXN * MAXN];

ll solve(int i, int j, int c){
    
    if(c == 0)
        return 0;
    if(dp[i][j][c] == -1){
        
        dp[i][j][c] = INFLL;
        
        int u = i * m + j;

        for(int x = 0; x < adj[u].size(); x++){
            
            int v = adj[u][x].first;
            ll w = adj[u][x].second;

            dp[i][j][c] = min(dp[i][j][c], w + solve(v / m, v % m, c - 1));
        } 
    }
    return dp[i][j][c];
}

int main(){
    optimize;

    ms(dp, -1);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            
            int u = i * m + j;
            int v = i * m + j + 1;
            ll c;
            
            cin >> c;

            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
        }
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            
            int u = i * m + j;
            int v = (i + 1) * m + j;
            ll c;
            
            cin >> c;

            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
        }
    }

    if(k % 2 != 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << -1 << " \n"[j==m-1];
            }
        }
    }
    else{

        vector<vector<ll>> ans(n, vector<ll>(m));

        k /= 2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                ans[i][j] = INFLL;

                for(int c = 1; c <= k; c++){
                    if(k % c == 0){
                        ans[i][j] = min(ans[i][j], 2 * (k / c) * solve(i, j, c));
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << ans[i][j] << " \n"[j==m-1];
            }
        }
    }
    
    return 0;   
}
