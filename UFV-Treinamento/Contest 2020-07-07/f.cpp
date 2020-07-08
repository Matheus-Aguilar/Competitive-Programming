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

    int t;
    cin >> t;

    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;

        string s;
        cin >> s;

        vector<vector<ll>> dp(n + 1, vector<ll>(2));

        dp[n][0] = b;
        dp[n][1] = INFLL;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '1'){
                dp[i][0] = INFLL;
                dp[i][1] = dp[i + 1][1] + a + 2 * b;
            }
            else{
                dp[i][0] = min(dp[i + 1][0] + a + b, dp[i + 1][1] + 2 * a + b);
                dp[i][1] = min(dp[i + 1][1] + a + 2 * b, dp[i + 1][0] + 2 * a + 2 * b);
            }
        }

        cout << dp[0][0] << "\n";
    }
    
    return 0;   
}
