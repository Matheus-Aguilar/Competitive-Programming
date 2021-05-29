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

int g, b, n;

bool check(ll d){
    ll cycles = d/(g + b);
    ll remainder = d % (g + b);
    ll high = g * cycles + min(remainder, (ll)g);
    ll low = min(n/2LL, b * cycles + max(0LL, remainder - g));
    return high + low >= n;
}

ll binSearch(ll l, ll r){
    while(l < r){
        ll m = l + (r - l)/2;
        if(check(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        cin >> n >> g >> b;
        cout << binSearch(1LL, 1000000000000000001LL) << "\n";
    }
    
    return 0;   
}
