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
        vector<ll> d(k + 1, INF);

        for(int i = 0; i < n; i++)
            cin >> p[i];
        
        sort(all(p));

        for(int i = 0; i < n; i++)
            for(int j = 1; j <= k; j++)
                d[j] = min(d[j], abs(j - p[i]));

        double ans = 0.0;

        for(int k1 = 1; k1 <= k; k1++){
            for(int k2 = k1; k2 <= k; k2++){
                
                double cont = 0.0;

                for(int i = 1; i <= k; i++){
                    if(abs(i - k1) < d[i] || abs(i - k2) < d[i])
                        cont++;
                }

                ans = max(ans, cont / k);
            }
        }

        cout << "Case #" << t << ": " << fixed << setprecision(9) << ans << "\n";
    }
    
    return 0;   
}
