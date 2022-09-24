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
    
    int t, m, n;
    cin >> t >> m >> n;

    vector<ll> prev(n + 2, 0);
    vector<ll> now(n + 2);
    for(int i = m; i <= n; i++)
        prev[i] = 1;

    while(--t){
        for(int i = m; i <= n; i++)
            now[i] = (prev[i - 1] + prev[i + 1]) mod;
        for(int i = m; i <= n; i++)
            prev[i] = now[i];
    }

    ll ans = 0;
    for(int i = m; i <= n; i++)
        ans = (ans + now[i]) mod;

    cout << ans << "\n";

    return 0;   
}
