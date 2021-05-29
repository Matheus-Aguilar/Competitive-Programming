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
#define MAXN 100100

using namespace std;

int n, q;
ll x, y, d[MAXN];

ll f(ll m){
    return abs(y - x - d[m]);
}

int ternarySearch(int l, int r){
    
    while(l < r){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        ll f1 = f(m1);
        ll f2 = f(m2);

        if(f1 > f2)
            l = m1 + 1;
        else
            r = m2 - 1;
    }

    return l;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> d[i];

    d[0] = 0;

    cin >> q;

    while(q--){
        cin >> x >> y;

        int pos = lower_bound(d, d + n + 1, y) - d;
        int best = ternarySearch(0, pos - 1);

        if(f(0) <= f(best))
            cout << 0 << "\n";
        else if(f(best - 1) <= f(best))
            cout << best - 1 << "\n";
        else
            cout << best << "\n";
    }
    
    return 0;   
}
