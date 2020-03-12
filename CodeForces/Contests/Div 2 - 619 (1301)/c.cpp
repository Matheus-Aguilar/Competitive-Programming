#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

ll PA(ll n){
    return (n * (n + 1))/2;
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        ll n, m;
        cin >> n >> m;

        ll ans = PA(n);

        ll x = (n - m)/(m + 1);
        ll y = (n - m) - x * (m + 1);
        
        ans -= (m + 1 - y) * PA(x) + y * PA(x + 1);

        cout << ans << "\n";
    }

    return 0;   
}
