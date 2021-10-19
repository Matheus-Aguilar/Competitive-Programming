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
#define MAXN 10100
#define MAXK 800

using namespace std;

int k, n;
ll l, t[MAXK][MAXK], p[MAXN], dp[MAXN][MAXK], sum[MAXN][MAXK];

int main(){
    optimize;
    
    cin >> k >> l;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cin >> t[i][j];
        }
    }
    
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        cin >> p[i];
    }

    for(int i = 0; i < k; i++){
        dp[n - 1][i] = 1;
    }

    sum[n - 1][0] = dp[n - 1][0];

    for(int i = 1; i < k; i++){
        sum[n - 1][i] = (sum[n - 1][i - 1] + dp[n - 1][i]) mod;
    }

    for(int i = n - 2; i >= 0; i--){
        
        for(int j = 0; j < k; j++){

            int up = upper_bound(t[j], t[j] + k, p[i] + l) - t[j];
            int low = lower_bound(t[j], t[j] + k, p[i] - l) - t[j];

            if(low > n - 1 || up <= 0) continue;

            if(low - 1 < 0)
                dp[i][j] = sum[i + 1][up - 1];
            else
                dp[i][j] = (sum[i + 1][up - 1] - sum[i + 1][low - 1] + 1000000007) mod;
        }

        sum[i][0] = dp[i][0];

        for(int j = 1; j < k; j++){
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) mod;
        }
    }

    ll ans = 0;

    for(int i = 0; i < k; i++){
        ans = (ans + dp[0][i]) mod;
    }

    cout << ans << "\n";

    return 0;   
}
