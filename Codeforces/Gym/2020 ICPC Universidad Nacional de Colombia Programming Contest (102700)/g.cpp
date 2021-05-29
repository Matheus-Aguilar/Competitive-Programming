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
#define MAXN 100100
 
using namespace std;

const int p = 1000000007;

ll f[MAXN];

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
 
    ll n, m, a, b, ans = 1LL;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
        cin >> a >> b;

    f[0] = 1LL;

    for(int i = 1; i <= n; i++)
        f[i] = (f[i - 1] * i) mod;

    while(m--){
        ll comb = (f[n] * fastExpo((2 * f[n - 2]) mod, p - 2)) mod;
        ans = (ans * comb) mod;
        n -= 2;
    }

    ans = (ans * f[n]) mod;

    cout << ans << "\n";
}