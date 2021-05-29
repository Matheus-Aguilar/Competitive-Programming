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
#define MAXN 401000

using namespace std;

int main(){
    optimize;

    int n, b;
    ll ans = 0;
    map<int, ll> m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b;
        m[b - i] += b;
    }
    for(map<int, ll>::iterator it = m.begin(); it != m.end(); it++)
        ans = max(ans, it->second);
    cout << ans << "\n";
    return 0;   
}
