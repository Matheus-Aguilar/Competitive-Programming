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

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        ll n, k;
        cin >> n >> k;

        vector<ll> p(n);
        vector<ll> d(n + 1, 0);

        for(int i = 0; i < n; i++)
            cin >> p[i];
        
        sort(all(p));

        ll ans = 0;

        for(int i = 0; i < n - 1; i++){
            ans = max(ans, p[i + 1] - p[i] - 1);
        }

        for(int i = 0; i < n - 1; i++){

            if(p[i + 1] - p[i] <= 1)
                continue;

            d[i] = (p[i + 1] - p[i] - 2) / 2 + 1;

        }

        d[n - 1] = p[0] - 1;
        d[n] = k - p[n - 1];

        sort(all(d));
        reverse(all(d));

        ans = max(ans, d[0] + d[1]);

        cout << "Case #" << t << ": " << fixed << setprecision(9) << (double) ans / k << "\n";
    }
    
    return 0;   
}
