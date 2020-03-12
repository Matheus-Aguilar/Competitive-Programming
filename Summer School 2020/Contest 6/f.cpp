#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAXN 410

using namespace std;

long double dp[MAXN][MAXN];

int main(){
    optimize;

    int n, k;
    cin >> n >> k;

    dp[k][0] = 1;

    for(int i = k - 1; i >= 0; i--){
        for(int j = 0; j <= n; j++){
            if(j == n - 1){
                dp[i][j] = dp[i + 1][j + 1]/2 + dp[i + 1][j]/2;
                if(j != 0)
                    dp[i][j] += dp[i + 1][j - 1]/2;
            }
            else if(j == 0)
                dp[i][j] = dp[i + 1][j]/2;
            else
                dp[i][j] = dp[i + 1][j - 1]/2 + dp[i + 1][j]/2;
        }
    }

    long double ans = 0;

    for(int i = 0; i <= n; i++)
        ans += i * dp[0][i];

    cout << fixed << setprecision(9) << ans << "\n";
}