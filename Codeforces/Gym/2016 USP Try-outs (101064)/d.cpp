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
#define MAXN 100100

using namespace std;

int n;
ll k, a[MAXN];

bool check(ll x){

    ll sum = 0;

    for(int i = 0; i < n; i++){
        sum += upper_bound(a, a + i, x - a[i]) - a;
    }

    return sum >= k;
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
        cin >> a[i];

    sort(a, a + n);

    cout << binSearch(0, INFLL) << "\n";
    
    return 0;   
}
