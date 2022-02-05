#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define pdd pair<double, double>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 220

using namespace std;

int n, dp[MAXN][MAXN]; 
pdd d[MAXN];

int solve(int i, int j){
    if(i > n)
        return 0;
    if(dp[i][j] == -1){
        dp[i][j] = solve(i + 1, j);
        if(d[i].first > d[j].first && d[i].second < d[j].second)
            dp[i][j] = max(dp[i][j], solve(i + 1, i) + 1);
    }
    return dp[i][j];
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        cin >> n;

        ms(dp, -1);

        for(int i = 1; i <= n; i++){
            cin >> d[i].first >> d[i].second;
        }

        d[0] = pdd(-1, 1000);

        cout << solve(1, 0) << "\n";
    }

    return 0;   
}
