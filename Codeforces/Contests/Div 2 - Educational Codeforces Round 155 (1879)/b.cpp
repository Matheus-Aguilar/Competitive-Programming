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

ll solve(vector<ll> &a, vector<ll> &b){
    ll best = *min_element(all(b));
    ll sum = 0;

    for(int i = 0; i < a.size(); i++){
        sum += a[i] + best;
    }

    return sum;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<ll> a(n), b(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        
        ll ans = solve(a, b);
        ans = min(ans, solve(b, a));

        cout << ans << "\n";
    }
    
    return 0;   
}
