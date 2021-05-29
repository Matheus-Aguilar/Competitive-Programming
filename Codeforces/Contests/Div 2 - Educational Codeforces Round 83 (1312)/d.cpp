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

const ll P = 998244353;

ll fat(ll n){
    if(!n) return 1LL;
    else return (n * fat(n - 1)) mod;
}

ll fastExp(ll x, ll k){
    
    ll ans = 1LL;
    x = x mod;
    
    while(k > 0){
        if(k & 1)
            ans = (ans * x) mod;
        k >>= 1;
        x = (x * x) mod;
    }
    return ans;
}

int main(int argc, char **argv){
    optimize;

    ll n, m;
    cin >> n >> m;

    ll fatM = fat(m);
    ll fatN = (fat(n - 1) * fat(m - n + 1)) mod;
    ll comb = (fatM * fastExp(fatN, P - 2)) mod;
    ll pot = fastExp(2, n - 3);

    if(n != 2)
        cout << (((comb * (n - 2)) mod) * pot) mod << "\n";
    else
        cout << 0 << "\n";

    return 0;   
}
