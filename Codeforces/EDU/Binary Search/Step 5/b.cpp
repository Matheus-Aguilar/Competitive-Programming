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

ll n, k;

bool check(ll m){
    
    ll cont = 0;

    for(ll i = 1; i <= n; i++){
        
        cont += min(m / i, n);
        
        if(cont >= k){
            return true;
        }
    }

    return false;
}

ll binSearch(ll l, ll r){
    
    while(l < r){
        ll m = l + (r - l)/2;

        if(!check(m))
            l = m + 1;
        else
            r = m;
    }

    return l;
}

int main(){
    optimize;

    cin >> n >> k;

    cout << binSearch(1LL, n * n) << "\n";
    
    return 0;   
}
