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
    
    if(n == 2)
        return 1;
    
    ll x = (n + 1) / 2 + 2LL * calc((n + 1) / 2);
    
    if(n % 2 != 0)
        x--;

    return x;
}

int main(){
    optimize;

    ll n;
    cin >> n;
    
    cout << calc(n) << "\n";

    return 0;   
}
