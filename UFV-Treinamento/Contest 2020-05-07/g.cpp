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

bool check(ll x, ll s){
    ll sum = 0, aux = x;
    while(aux > 0){
        sum += aux % 10LL;
        aux /= 10LL;
    }
    return (x - sum) >= s;
}

ll binSearch(ll l, ll r, ll s){
    while(l < r){
        ll m = l + (r - l)/2;
        if(check(m, s))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    optimize;

    ll n, s;
    cin >> n >> s;

    cout << n - binSearch(1LL, n + 1, s) + 1LL << "\n";

    return 0;   
}
