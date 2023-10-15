#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod 998244353
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        ll y = sqrt(n);
        ll sum = 0;

        for(int i = 1; i <= y; i++){
            
            ll x = i - 1;
            ll z = n / i - i;

            ll c[4];

            c[0] = 6 * ((x * z) % mod) % mod;
            c[1] = (3 * z) % mod;
            c[2] = (3 * x) % mod;
            c[3]= 1;

            for(int j = 0; j < 4; j++)
                sum = (sum + c[j]) % mod;
        }

        cout << sum << "\n";
    }
    
    return 0;   
}
