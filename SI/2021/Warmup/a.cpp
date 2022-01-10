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

ll solve(ll n){
    if(n <= 0)
        return 1LL;
    return n * solve(n - 2);
}

int main(){
    optimize;

    ll n;

    cin >> n;
    cout << solve(n) << "\n";

    return 0;   
}
