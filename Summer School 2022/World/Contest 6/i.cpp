#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 1010

using namespace std;

int n, k;
ll dp[MAXN][MAXN][2];

ll solve(int i, int j, int l){
    if(i < 0 || i >= n)
        return 1;
    if(dp[i][j][l] == -1){
        if(l == 0){
            dp[i][j][l] = solve(i + 1, j, 0);
            if(j > 1)
                dp[i][j][l] += solve(i - 1, j - 1, 1);
        }
        else {
            dp[i][j][l] = solve(i - 1, j, 1);
            if(j > 1)
                dp[i][j][l] += solve(i + 1, j - 1, 0);
        }
        dp[i][j][l] %= mod;
    }
    return dp[i][j][l];
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){

        ms(dp, -1);

        cin >> n >> k;

        cout << solve(0, k, 0) << "\n";
    }

    return 0;
}
