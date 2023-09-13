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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        ll best = 0LL;

        vector<ll> a(n + 1);

        for(int i = 1; i <= n; i++){
            for(int j = 1, k = 1; j < i; j++, k++){
                a[j] = k;
            }
            for(int j = i, k = n; j <= n; j++, k--){
                a[j] = k;
            }

            ll sum = 0LL, big = 0LL;

            for(int j = 1; j <= n; j++){
                sum += a[j] * j;
                big = max(big, a[j] * j);
            }

            best = max(best, sum - big);
        }

        cout << best << "\n";
    }
    
    return 0;   
}
