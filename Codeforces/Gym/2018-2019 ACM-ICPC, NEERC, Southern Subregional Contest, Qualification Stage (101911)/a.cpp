#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int main() {
    optimize;

    int n;
    ll m, d;

    cin >> n >> m >> d;

    set<ll> a;
    map<ll, int> pos;
    
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;

        a.insert(x);
        pos[x] = i;
    }

    int day = 1;
    ll low = 1;

    while(!a.empty()){
        
        auto it = a.lower_bound(low);
        
        if(it != a.end()){
            ll x = *it;
            ans[pos[x]] = day;
            low = x + d + 1;
            a.erase(x);
        } else {
            day++;
            low = 1;
        }
    }

    cout << *max_element(ans.begin(), ans.end()) << "\n";

    for(int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];

    return 0;
}