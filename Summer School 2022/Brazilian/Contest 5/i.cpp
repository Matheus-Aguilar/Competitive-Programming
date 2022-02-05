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
#define MAXN 500

using namespace std;

int n, k, d;
ll dp[MAXN][MAXN];

ll solve(int u, bool b){
    if(u < 0)
        return 0;
    if(u == 0)
        return b;
    if(dp[u][b] == -1){
        dp[u][b] = 0;
        for(int i = 1; i <= k; i++){
            dp[u][b] = (dp[u][b] + solve(u - i, b || (i >= d))) mod;
        }
    }
    return dp[u][b];
}

int main(){
    optimize;

    ms(dp, -1);
    
    cin >> n >> k >> d;

    cout << solve(n, false) << "\n";

    return 0;   
}
