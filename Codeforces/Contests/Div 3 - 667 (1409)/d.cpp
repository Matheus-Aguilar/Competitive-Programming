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

ll calc(ll n){
    ll sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        ll n, p = 10, ans = 0;
        int s;

        cin >> n >> s;

        while(calc(n) > s){
            ans += p - n % p;
            n += p - n % p;
            p *= 10;
        }

        cout << ans << "\n";
    }

    return 0;   
}
