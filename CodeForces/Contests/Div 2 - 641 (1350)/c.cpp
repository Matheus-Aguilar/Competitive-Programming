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

ll gcd(ll a, ll b){
    return (b ? gcd(b, a % b) : a);
}

ll lcm(ll a, ll b){
    return (a * b)/gcd(a, b);
}

int main(){
    optimize;

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> prefix(n);
    vector<ll> suffix(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    prefix[0] = a[0];
    for(int i = 1; i < n; i++)
        prefix[i] = gcd(prefix[i - 1], a[i]);
    suffix[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--)
        suffix[i] = gcd(suffix[i + 1], a[i]);
    ll ans = 1;
    for(int i = 0; i < n; i++)
        ans = lcm(ans, gcd((i ? prefix[i - 1] : 0LL), (i != n - 1 ? suffix[i + 1] : 0LL)));
    cout << ans << "\n";
    return 0;   
}
