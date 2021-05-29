#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    ll n, m;

    cin >> n >> m;

    vector<ll> a(n);

    cin >> a[0];

    for(int i =  1; i < n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    while(m--){
        ll b;
        cin >> b;

        vector<ll>::iterator it = lower_bound(a.begin(), a.end(), b);
        ll dorm = (ll)(it - a.begin());
        ll room = b - (dorm ? a[dorm - 1] : 0);

        cout << dorm + 1 << " " << room << "\n";
    }
    
    return 0;   
}
