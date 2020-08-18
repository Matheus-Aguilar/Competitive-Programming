#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 998244353
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

int main(){
    optimize;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> a(n, vector<ll>(m));
    vector<ll> r(n, 0);
    vector<ll> c(m, 0);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    while(k--){
        char op; int x; ll t;
        cin >> op >> x >> t;
        if(op == 'r')
            r[x - 1] = t;
        else
            c[x - 1] = t;
    }

    ll ans = 0LL;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans = (ans + ((max(r[i], c[j]) mod) * (a[i][j] mod)) mod) mod;    
    
    cout << ans << "\n";
    
    return 0;   
}
