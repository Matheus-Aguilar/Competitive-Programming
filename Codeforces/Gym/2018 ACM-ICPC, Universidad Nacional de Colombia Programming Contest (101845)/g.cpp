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
#define MAXN 5010
#define MAXQ 1100

using namespace std;

const ll p = 1000000007;

int n, m;
ll dp[MAXN][MAXN], prob[26], inv[MAXQ];
string s;

ll fastExpo(ll x, int y){
    ll r = 1;
    while(y > 0){
        if(y & 1)
            r = (r * x) mod;
        x = (x * x) mod;
        y >>= 1;
    }
    return r;
}

ll solve(int i, int j){
    if(j == m)
        return 1;
    if(i == n)
        return 0;
    if(dp[i][j] == -1){
        int c = (int)(s[j] - 'a');

        ll hit = (prob[c] * solve(i + 1, j + 1)) mod;
        ll miss = ((1 - prob[c] + p) mod * solve(i + 1, j)) mod;

        dp[i][j] = (hit + miss) mod;
    }
    return dp[i][j];
}

int main(){
    optimize;

    ms(dp, -1);

    for(int i = 0; i < MAXQ; i++)
        inv[i] = fastExpo(i, p - 2);
    
    cin >> n >> m >> s;

    for(int i = 0; i < 26; i++){
        ll p, q;
        cin >> p >> q;
        prob[i] = (p * inv[q]) mod;
    }

    cout << solve(0, 0) << "\n";

    return 0;   
}
