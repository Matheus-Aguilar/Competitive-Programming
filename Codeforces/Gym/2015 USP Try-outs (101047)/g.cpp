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

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        vector<ll> f(k);

        for(int i = 0; i < k; i++)
            cin >> f[i];
        
        for(int i = 0; i < k; i++){

            ll g = gcd(n, f[i]);

            while(g != 1){
                while(n % g == 0){
                    n /= g;
                }
                g = gcd(n, f[i]);
            }
        }

        cout << (n == 1 ? "Y" : "N") << "\n";
    }
    
    return 0;   
}
