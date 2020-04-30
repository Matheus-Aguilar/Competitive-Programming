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

int main(){
    optimize;

    ll u, v;
    cin >> u >> v;
    ll x = (v - u)/2;

    if(u > v || ((u ^ v) & 1))
        cout << -1 << "\n";
    else if(u == v && !u)
        cout << 0 << "\n";
    else if(u == v)
        cout << 1 << "\n" << u << "\n";
    else{
        if(((u + x) ^ x) == u)
            cout << 2 << "\n" << u + x << " " << x << "\n";
        else
            cout << 3 << "\n" << u << " " << x << " " << x << "\n";
    }

    return 0;   
}
