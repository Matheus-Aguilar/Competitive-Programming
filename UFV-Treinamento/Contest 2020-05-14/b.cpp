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

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<ll>> dp(n - m + 2, vector<ll>(n - m + 2, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n - m; i++){
        dp[i][0] = dp[i - 1][1];
        for(int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) mod;
    }

    int op = 0, cl = 0;
    int minBal = 0, bal;
    
    for(int i = 0; i < m; i++){
        if(s[i] == '(')
            op++;
        else
            cl++;
        minBal = max(minBal, cl - op);
    }
    bal = op - cl;

    ll ans = 0;
    for(int i = 0; i <= (n - m); i++)
        for(int j = 0; j <= i; j++)
            if(j >= minBal && j + bal >= 0 && j + bal <= (n - m))
                ans = (ans + ((dp[i][j] * dp[(n - m) - i][j + bal]) mod)) mod;

    cout << ans << "\n";

    return 0;   
}
