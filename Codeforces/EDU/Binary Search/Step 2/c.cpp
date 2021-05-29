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

int n, x, y;

bool check(ll t){

    ll c = 0;

    if(t >= x){

        c++;

        c += (t - x)/x;
        c += (t - x)/y;
    }

    return c >= n;
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
    
    cin >> n >> x >> y;

    if(x > y) swap(x, y);

    cout << binSearch(0, INFLL) << "\n";

    return 0;   
}
