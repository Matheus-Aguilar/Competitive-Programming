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

ll fastExpo(ll x, ll y){
    ll r = 1LL;
    while(y > 0LL){
        if(y & 1)
            r = (r * x) mod;
        x = (x * x) mod;
        y >>= 1;
    }
    return r;
}

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    ll cont = 0, ans = 0;
    for(int i = 0; i < m; i++){
        if(b[i] == '1')
            cont++;
        
        if(n - m + i >= 0 && a[n - m + i] == '1'){
            ans = (ans + (cont * fastExpo(2LL, m - i - 1) mod)) mod;
        }
    }

    cout << ans << "\n";
    
    return 0;   
}
