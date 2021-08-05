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

ll sum(ll x){
    return (x * (x + 1)) / 2;
}

ll binSearch(ll l, ll r, ll s){
    while(l < r){
        ll m = l + (r - l) / 2;

        if(sum(m) > s)
            r = m;
        else
            l = m + 1;
    }
    return l - 1;
}

int main(){
    optimize;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        ll s;
        cin >> s;
        cout << binSearch(0LL, 2000000000LL, s) << "\n";
    }
    
    return 0;   
}
