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
#define fi first
#define se second

using namespace std;

typedef pair<long double, long double> pdd;
typedef pair<ll, ll> pll;

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    vector<pll> p(n);
    vector<ll> det(n);
    vector<ll> pre(n, 0.0);

    for(int i = 0; i < n; i++)
        cin >> p[i].fi >> p[i].se;
    
    for(int i = 0; i < n; i++)
        det[i] = p[(i + 1) % n].fi * p[i].se - p[(i + 1) % n].se * p[i].fi;

    pre[0] = det[0];

    for(int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + det[i];

    ll area = abs(accumulate(all(det), 0LL));

    ll best = -INFLL;

    while(m--){
        int a, b;
        cin >> a >> b;
        
        --a, --b;

        if(a > b) 
            swap(a, b);

        ll calc;
        
        if(a > 0)
            calc = pre[b - 1] - pre[a - 1];
        else
            calc = pre[b - 1];

        //cout << calc << " " << p[a].fi * p[b].se - p[a].se * p[b].fi << " ";

        calc += p[a].fi * p[b].se - p[a].se * p[b].fi;

        calc = abs(calc);

        //cout << calc << "\n";

        best = max(best, min(area - calc, calc));
    }

    cout << fixed << setprecision(9) << best/2.0L << "\n";

    return 0;   
}
