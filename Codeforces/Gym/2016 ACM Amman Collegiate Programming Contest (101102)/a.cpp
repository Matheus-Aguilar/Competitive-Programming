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

void solve(int n, vector<int> &c, vector<ll> &dp, int w){
    
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = w; j >= 0; j--){
            if(c[i] + j <= w){
                dp[c[i] + j] = (dp[c[i] + j] + dp[j]) mod;
            }
        }
    }
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, m, k, w;
        cin >> n >> m >> k >> w;

        vector<int> cn(n);
        vector<int> cm(m);

        vector<ll> dpn(w + 1, 0);
        vector<ll> dpm(w + 1, 0);

        for(int i = 0; i < n; i++)
            cin >> cn[i];

        for(int i = 0; i < m; i++)
            cin >> cm[i];

        solve(n, cn, dpn, w);
        solve(m, cm, dpm, w);

        ll ans = 0;

        for(int i = 0; i <= w; i++){
            int j = w - i;

            if(abs(i - j) <= k){
                ll prod = (dpn[i] * dpm[j]) mod;
                ans = (ans + prod) mod;
            }
        }

        cout << ans << "\n";
    }

    return 0;   
}
