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

int main(){
    optimize;
    
    ll m, x;
    long double p, j;
    cin >> m >> p >> j >> x;
    p /= 100.0L, j /= 100.0L;
    
    ll ans = (ll)(log2((1.0L * x)/(m * j))/log2(1.0L - p));
    cout << max(ans, 0LL) << "\n";

    return 0;   
}
