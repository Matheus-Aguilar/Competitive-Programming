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

    int n, m;
    cin >> n >> m;

    int a1, a2;
    cin >> a1 >> a2;

    vector<ll> a(n - 2);

    for(int i = 0; i < n - 2; i++)
        cin >> a[i];

    sort(all(a));

    ll ans = INFLL;

    for(int i = 0; i + m - 1 < a.size(); i++){
    
        int j = i + m - 1;

        ll cost = 0;

        if(a1 > a[i])
            cost += a1 - a[i];
        if(a2 < a[j])
            cost += a[j] - a2;

        ans = min(ans, cost);
    }

    cout << ans << "\n";
    
    return 0;   
}
