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
#define MAXN 200200

using namespace std;

int n, k;
ll c[MAXN], v[MAXN], dp[MAXN][20];

ll solve(int i, int j){
    if(i == n)
        return 0;
    if(dp[i][j] == -1){
        if(j > 0)
            dp[i][j] = max(solve(i + 1, j), min(v[i] - c[i], solve(i + 1, j - 1) - c[i]));
        else
            dp[i][j] = max(solve(i + 1, j), v[i] - c[i]);
    }
    return dp[i][j];
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        cin >> n >> k;

        ms(dp, -1);

        for(int i = 0; i < n; i++)
            cin >> v[i] >> c[i];
        
        cout << solve(0, k) << "\n";
    }

    return 0;   
}
