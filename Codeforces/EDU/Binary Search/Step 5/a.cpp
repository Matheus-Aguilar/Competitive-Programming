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
#define MAXN 50
#define fi first
#define se second

using namespace std;

int n, k;
pair<ll, ll> seg[MAXN];

bool check(ll m){

    ll cont = 0;

    for(int i = 0; i < n; i++){
        
        cont += max(min(m, seg[i].se) - seg[i].fi + 1LL, 0LL);

        if(cont >= k + 1)
            return true;
    }

    return false;
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

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> seg[i].fi >> seg[i].se;

    cout << binSearch(-INFLL, INFLL) << "\n";

    return 0;   
}
