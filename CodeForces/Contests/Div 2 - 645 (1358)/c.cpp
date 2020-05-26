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

ll sum(ll n){
    return (n * (n + 1))/2;
}

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (x2 - x1) * (y2 - y1) + 1 << "\n";
    }

    return 0;   
}
