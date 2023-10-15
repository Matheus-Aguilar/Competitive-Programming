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
#define MAXN 1100

using namespace std;

int n, x, t[MAXN];
ll dp[12345];

ll fastExpo(ll a, ll b){
    ll r = 1;
    while(b > 0){
        if(b & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

int main(){
    optimize;

    cin >> n >> x;

    for(int i = 0; i < n; i++)
        cin >> t[i];

    ll inv = fastExpo(n, mod - 2);
    
    dp[0] = 1;

    for(int i = 0; i <= x; i++){
        for(int j = 0; j < n; j++){
            
            int k = i + t[j];
            ll val = (dp[i] * inv) % mod;
            
            if(k <= x){
                dp[k] = (dp[k] + val) % mod; 
            }
        }
    }

    ll ans = 0;

    for(int i = max(x - t[0] + 1, 0); i <= x; i++){
        ll val = (dp[i] * inv) % mod;
        ans = (ans + val) % mod;
    }

    cout << ans << "\n";

    return 0;   
}
