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

ll solve(ll a, ll b){

    if(a < 1 || b < 1)
        return 0;
    if(a > b)
        return solve(b, a);
    
    ll g = __gcd(a, b);
    if(g > 1)
        return solve(a / g - 1, b / g - 1) + 1;
    
    ll d = b - a;
    ll best = 0;

    for(ll i = 1; i * i <= d; i++){
        if(d % i == 0){
            ll x = d / i;
            if((a / i) * i < a)
                best = max(best, (a / i) * i);
            if((a / x) * x < a)
                best = max(best, (a / x) * x);
        }
    }

    return solve(best, best + d) + (a - best);
}

int main(){
    optimize;

    ll a, b;
    cin >> a >> b;

    cout << solve(a, b) << "\n";
    
    return 0;   
}
