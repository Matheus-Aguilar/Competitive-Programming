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

ll maxDigit(ll a){
    ll d = -1;
    while(a > 0){
        d = max(d, a % 10);
        a /= 10;
    }
    return d;
}

ll minDigit(ll a){
    ll d = 10;
    while(a > 0){
        d = min(d, a % 10);
        a /= 10;
    }
    return d;
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        ll a, a0, a2, k;
        cin >> a >> k;
        while(--k && minDigit(a) > 0)
            a = a + minDigit(a) * maxDigit(a);
        cout << a << "\n";
    }
    
    return 0;   
}
