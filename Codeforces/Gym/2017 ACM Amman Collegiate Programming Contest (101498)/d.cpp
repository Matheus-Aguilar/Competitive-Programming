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
#define MAXN 200200

using namespace std;

const ll p = 1000000007;

ll f[MAXN];

void precalc(){
    f[0] = 1;
    for(int i = 1; i < MAXN; i++) 
        f[i] = (i * f[i - 1]) mod;
}

ll fastExpo(ll x, ll y){
    
    ll r = 1;

    while(y > 0){
        if(y & 1) r = (r * x) mod;
        x = (x * x) mod;
        y >>= 1;
    }

    return r;
}

ll comb(ll n, ll k){
    ll num = f[n + k - 1];
    ll dem = (f[n - 1] * f[k]) mod;

    return (num * fastExpo(dem, p - 2)) mod;
}

int main(){
    optimize;

    precalc();

    int t;
    cin >> t;

    while(t--){
        ll a, b, ans = 0;
        cin >> a >> b;
        cout << (2 * comb(b + 1, a - b - 1)) mod << "\n";
    }
    
    return 0;   
}