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
#define MAXN 5050

using namespace std;

int n, a[MAXN];
ll dp[MAXN];

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    dp[n] = 1LL;

    for(int i = n - 1; i >= 0; i--){
        
        int m = a[i];

        for(int j = i + 1; j < n; j++){
            m = min(m, a[j]);
            if(a[i] == m || a[j] == m){
                dp[i] = (dp[i] + dp[j]) % mod;
            }
        }

        if(m == a[i]){
            dp[i] = (dp[i] + dp[n]) % mod;
        }
    }

    ll ans = 0;

    for(int i = 0, m = INF; i < n; i++){
        m = min(m, a[i]);
        if(a[i] == m){
            ans = (ans + dp[i]) % mod;
        }
    }

    cout << ans << "\n";

    return 0;   
}
