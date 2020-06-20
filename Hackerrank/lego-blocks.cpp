#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007LL
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 1010

using namespace std;

const ll p = 1000000007LL;

int n, m;
ll dp[MAXN];
ll total[MAXN];
ll valid[MAXN];

void preCalc(){
    dp[0] = 1LL, dp[1] = 1LL, dp[2] = 2LL, dp[3] = 4LL;
    for(int i = 4; i < MAXN; i++)
        dp[i] = ((dp[i - 1] + dp[i - 2]) mod + (dp[i - 3] + dp[i - 4]) mod) mod;
}

ll fastExpo(ll x, int y){
    ll r = 1LL;
    while(y > 0){
        if(y & 1)
            r = (r * x) mod;
        x = (x * x) mod;
        y >>= 1;
    }
    return r;
}

int main(){
    optimize;

    preCalc();

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i <= m; i++)
            total[i] = fastExpo(dp[i], n);
        for(int i = 1; i <= m; i++){
            valid[i] = total[i];
            for(int j = 1; j < i; j++)
                valid[i] = (valid[i] - (valid[j] * total[i - j]) mod + p) mod;
        }
        cout << valid[m] << "\n";
    }
    
    return 0;   
}
