#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    ll n, q;
    cin >> n >> q;

    vector<ll> a(n, 0);

    cin >> a[0];

    for(int i = 1; i < n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    ll k, deaths = 0, acu = 0;
    vector<ll>::iterator it;

    while(q--){
        cin >> k;

        acu += k;

        it = upper_bound(a.begin(), a.end(), acu);
        deaths = (ll)(it - a.begin());
        if(deaths >= n) deaths = acu = 0;

        cout << n - deaths << "\n";
    }

    return 0;   
}
