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

const ll p = 1000000007;
ll expo[100010];

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

int main(){
    optimize;
    
    for(int i = 0; i <= 100001; i++)
        expo[i] = fastExpo(i, p - 2);

    int t;
    cin >> t;

    while(t--){
        int n;
        
        cin >> n;

        vector<ll> a(n);
        
        for(int i = 0; i < n; i++)
            cin >> a[i];

        // if(n == 0){
        //     cout << 0 << "\n";
        //     continue;
        // }

        ll ans = n;
        ll prod = 1LL;

        for(int i = 0; i < n; i++)
            prod = (a[i] * prod) mod;
        
        ans = (ans * prod) mod;

        for(int i = 0; i < n; i++)
            ans = (ans - (prod * expo[a[i]]) mod + p) mod;

        cout << ans << "\n";
    }

    return 0;   
}