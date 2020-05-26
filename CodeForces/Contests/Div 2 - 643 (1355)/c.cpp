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

//y - x < z < x + y

ll sum(ll n){
    return (n * (n + 1))/2;
}

int main(){
    optimize;

    int a, b, c, d;
    ll ans = 0;
    cin >> a >> b >> c >> d;

    for(ll x = b, y = b; x >= a && y <= c; x--){
        while(x + y <= c)
            y++;
        int z = x + y - 1;

        if(z >= d){
            ans += (d - c + 1) * (c - y + 1);
        }
        else{
            if(c - y + 1 <= d - z + 1){
                ans += sum(c - y + 1) + (c - y + 1) * (z - c);
            }
            else{
                ans += sum(d - z + 1) + (c - y + 1) * (z - c) + ((c - y + 1) - (d - z + 1)) * (d - z + 1);
            }
        }
    }

    cout << ans << "\n";

    return 0;   
}
