#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<long long int, long long int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 200100

using namespace std;

ll a[2 * MAXN];
ll p[2 * MAXN];
ll d[2 * MAXN];

ll sum(ll n, ll m){
    return (n * (n + 1))/2 - (m * (m + 1))/2;
}

int main(){
    optimize;

    ll n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[n + i] = a[i];
    }

    for(int i = 0; i < 2 * n; i++){
        p[i + 1] = sum(a[i], 0) + p[i];
        d[i + 1] = a[i] + d[i];
    }
    
    ll ans = 0;
    
    for(int i = 0; i < n; i++){
        int j = lower_bound(d, d + 2 * n + 1, d[i + 1] + x - 1) - d - 1;
        if(i % n != j % n)
            ans = max(ans, p[j] - p[i + 1] + a[i] + sum(d[i + 1] + x - d[j] - 1, 0));
        else
            ans = max(ans, a[i]);
    }

    int k = lower_bound(d, d + 2 * n + 1, x) - d - 1;

    for(int i = k; i < n + k; i++){
        int j = lower_bound(d, d + 2 * n + 1, d[i + 1] - x + 1) - d - 1;
        if(i % n != j % n)
            ans = max(ans, p[i + 1] - p[j + 1] + sum(a[j], d[i + 1] - x - d[j]));
        else
            ans = max(ans, sum(a[j], a[j] - x));
    }

    cout << ans << "\n";

    return 0;   
}
