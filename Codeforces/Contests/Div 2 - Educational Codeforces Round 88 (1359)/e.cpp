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

using namespace std;

const ll p = 998244353;

ll fastExpo(ll x, ll y){
    ll r = 1LL;
    while(y > 0){
        if(y & 1)
            r = (r * x) mod;
        x = (x * x) mod;
        y >>= 1;
    }
    return r;
}

ll comb(ll x, ll y, vector<ll> &fat){
    return (fat[x] * fastExpo((fat[y] * fat[x - y]) mod, p - 2)) mod;
}

int main(){
    optimize;
    
    ll n, k, ans = 0LL;
    cin >> n >> k;

    vector<ll> fat(n + 1, 1LL);
    for(int i = 1; i <= n; i++)
        fat[i] = (i * fat[i - 1]) mod;
    
    for(int i = 1; i <= n; i++){
        if(n/i >= k)
            ans = (ans + comb(n/i - 1, k - 1, fat)) mod;
    }

    cout << ans << "\n";

    return 0;   
}
