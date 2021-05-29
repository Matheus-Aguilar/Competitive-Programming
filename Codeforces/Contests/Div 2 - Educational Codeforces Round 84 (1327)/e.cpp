#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 998244353
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 200100

using namespace std;

ll dp[MAXN];
ll d[MAXN];
ll s[MAXN];
ll p[MAXN];

int main(){
    optimize;

    int n;
    cin >> n;

    //Base
    dp[1] = 10, s[1] = 0, d[1] = 0, p[1] = 10;

    for(int i = 2; i <= n; i++)
        p[i] = (p[i - 1] * 10) mod;

    for(int i = 2; i <= n; i++){
        d[i] = (((d[i - 1] + s[i - 1]) mod) + (2 * dp[i - 1]) mod) mod;
        s[i] = (s[i - 1] + dp[i - 1]) mod;
        dp[i] = ((i * p[i]) mod - d[i] + 998244353) mod;
    }

    for(int i = n; i > 0; i--)
        cout << dp[i] << " ";
    cout << "\n";
    return 0;   
}
