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

ll n;

pair<ll, ll> g(ll m){
    
    ll a = m, b = n;

    while(b - a <= a && b - a > 0){
        ll aux = a;
        a = b - a;
        b = aux;
    }

    return make_pair(b, a);
}

pair<ll, ll> ternarySearch(ll l, ll r){
    while(l < r){

        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;

        pair<ll, ll> g1 = g(m1);
        pair<ll, ll> g2 = g(m2);

        if(g1 > g2)
            l = m1 + 1;
        else
            r = m2 - 1;
    }

    return g(l);
}

int main(){
    optimize;
    
    int T;
    cin >> T;

    while(T--){
        
        cin >> n;

        pair<ll, ll> ans = ternarySearch(n / 2, n - 1);
        
        cout << ans.second << " " << ans.first << "\n";
    }

    return 0;   
}
