#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

ll n, m;

ll calc(ll x1, ll x2, ll y1, ll y2){
    return x1 * (n - x2 + 1) * y1 * (m - y2 + 1);
}

ll calc(const vector<ll> &x, const vector<ll> &y, int k, int mask){
    
    if(mask == 0)
        return 0;

    ll minx = INF, maxx = -INF, miny = INF, maxy = -INF;
    
    for(int i = 0; i < k; i++){
        if((1 << i) & mask){
            minx = min(minx, x[i]);
            miny = min(miny, y[i]);
            maxx = max(maxx, x[i]);
            maxy = max(maxy, y[i]);
        }
    }

    return calc(minx, maxx, miny, maxy);
}

int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){

        cin >> n >> m;

        int k;
        cin >> k;

        vector<ll> x(k), y(k);

        for(int i = 0; i < k; i++){
            cin >> x[i] >> y[i];
        }

        int maxMask = (1 << k);
        ll cnt = 0;

        for(int i = 0; i < maxMask; i++){
            if(__builtin_popcount(i) % 2)
                cnt += calc(x, y, k, i);
            else
                cnt -= calc(x, y, k, i);
        }

        ll rows = ((n + 1) * n) / 2;
        ll cols = ((m + 1) * m) / 2;

        cout << rows * cols - abs(cnt) << "\n";
    }

    return 0;
}