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

    ll n, h, k, pos = 0, ans = 0, sz = 0;
    cin >> n >> h >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    while(pos < n){
        if(sz + v[pos] <= h)
            sz += v[pos++];
        else{
            ans += (sz + v[pos] - h + k - 1)/k;
            sz = max(0LL, sz - k * ((sz + v[pos] - h + k - 1)/k));
        }
    }

    ans += (sz + k - 1)/k;

    cout << ans << "\n";

    return 0;   
}
