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

typedef pair<ll, ll> pll;

struct Event{
    ll l, r, v;
    Event(ll _l = 0, ll _r = 0, ll _v = 0) : l(_l), r(_r), v(_v){}
    bool operator<(const Event &e) const{
        return l < e.l;
    }
    ll sum() const{
        return v * (r - l + 1);
    }
};

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        int m, k;
        cin >> m >> k;

        vector<Event> e(m + 2);
        vector<pll> prefix(m + 2);
        
        for(int i = 0; i < m; i++)
            cin >> e[i].l >> e[i].r >> e[i].v;

        e[m] = Event(-INF, -INF, 0);
        e[m + 1] = Event(INF, INF, 0);
        
        sort(all(e));

        prefix[0] = pll(e[0].r, e[0].sum());

        for(int i = 1; i < m + 2; i++){
            prefix[i] = prefix[i - 1];
            prefix[i].first = e[i].r;
            prefix[i].second += e[i].sum();
        }

        ll best = -INFLL;

        for(int i = 1; i <= m; i++){
            ll l = e[i].l, r = e[i].l + k - 1;
            
            int posR = lower_bound(all(prefix), pll(r, INF)) - prefix.begin() - 1;
            int posL = lower_bound(all(prefix), pll(l - 1, INF)) - prefix.begin() - 1;

            ll sum = prefix[posR].second - prefix[posL].second;

            if(posR <= m && e[posR + 1].l <= r)
                sum += (r - e[posR + 1].l + 1) * e[posR + 1].v;
            
            if(posL <= m && e[posL + 1].l <= l)
                sum -= (l - e[posL + 1].l) * e[posL + 1].v;

            best = max(sum, best);
        }

        for(int i = 1; i <= m; i++){
            ll l = e[i].r - k + 1, r = e[i].r;
            
            int posR = lower_bound(all(prefix), pll(r, INF)) - prefix.begin() - 1;
            int posL = lower_bound(all(prefix), pll(l - 1, INF)) - prefix.begin() - 1;

            ll sum = prefix[posR].second - prefix[posL].second;

            if(posR <= m && e[posR + 1].l <= r)
                sum += (r - e[posR + 1].l + 1) * e[posR + 1].v;
            
            if(posL <= m && e[posL + 1].l <= l)
                sum -= (l - e[posL + 1].l) * e[posL + 1].v;
            
            best = max(sum, best);
        }

        cout << best << "\n";
    }

    return 0;   
}
