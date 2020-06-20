#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>
#define mod % 1000000007LL

using namespace std;

ll fastExp(ll n, ll k){
    ll ans = 1;
    while(k){
        if(k & 1) ans = (ans * n) mod;
        k >>= 1;
        n = (n * n) mod;
    }
    return ans;
}

int main(){
    optimize;

    ll t, n;
    cin >> t;
    
    while(t--){
        cin >> n;
        ll acu = 0;
        ll exp = fastExp(2LL, n - 1);
        while(n--){
            ll x;
            cin >> x;
            acu |= x;
        }
        cout << (acu * exp) mod << "\n";
    }

    return 0;   
}
