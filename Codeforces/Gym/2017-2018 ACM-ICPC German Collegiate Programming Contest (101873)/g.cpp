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
#define fi first
#define se second

using namespace std;

int n;
pair<ll, ll> p[MAXN];

ll getArea(){
    
    ll area = 0LL;
    
    for(int i = 0; i < n; i++){
        int j = (i + 1) % n;
        
        area += (p[i].fi * p[j].se) - (p[i].se * p[j].fi);
    }
    
    return abs(area);
}

ll getBorder(){
    
    ll cont = 0;

    for(int i = 0; i < n; i++){
        
        int j = (i + 1) % n;

        if(p[i].fi == p[j].fi)
            cont += abs(p[i].se - p[j].se) - 1;
        else if(p[i].se == p[j].se)
            cont += abs(p[i].fi - p[j].fi) - 1;
        else
            cont += __gcd(abs(p[i].fi - p[j].fi), abs(p[i].se - p[j].se)) - 1;
    }

    return cont;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    
    ll A = getArea(), B = getBorder() + n;
    
    cout << (A - B + 2)/2 << "\n";

    return 0;   
}
