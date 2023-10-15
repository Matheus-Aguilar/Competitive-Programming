#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod 998244353
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 200200

using namespace std;

string s;
vector<vector<ll>> dp, dp2;

ll solve(int i, int j){
    if(i == s.size())
        return 0;
    if(dp[i][j] == -1){
        int b = s[i] - '0';
        dp[i][j] = solve(i + 1, j) + 1;
        if(b != j)
            dp[i][j] = min(dp[i][j], solve(i + 1, b));
    }
    return dp[i][j];
}

ll solve2(int i, int j){
    if(i == s.size())
        return 1;
    if(dp2[i][j] == -1){
        
        int b = s[i] - '0';
        dp2[i][j] = 0;

        if(b != j){
            
            ll val1 = solve(i + 1, j) + 1;
            ll val2 = solve(i + 1, b);
            
            if(val1 <= val2)
                dp2[i][j] = (dp2[i][j] + solve2(i + 1, j)) % mod;
            if(val2 <= val1)
                dp2[i][j] = (dp2[i][j] + solve2(i + 1, b)) % mod;
        } else {
            dp2[i][j] = solve2(i + 1, j);
        }
    }
    return dp2[i][j];    
}

ll fat(ll n){
    ll prod = 1;
    for(int i = 1; i <= n; i++)
        prod = (prod * i) % mod;
    return prod;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        cin >> s;
        
        dp.assign(s.size(), vector<ll>(3, -1));
        dp2.assign(s.size(), vector<ll>(3, -1));
        
        ll ans1 = solve(0, 2);
        ll ans2 = solve2(0, 2);

        ans2 = (ans2 * fat(ans1)) % mod;

        cout << ans1 << " " << ans2 << "\n";
    }
    
    return 0;   
}
