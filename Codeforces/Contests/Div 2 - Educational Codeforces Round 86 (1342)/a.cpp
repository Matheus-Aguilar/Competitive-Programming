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

    int t;
    cin >> t;
    while(t--){
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
    
        if(2 * a <= b)
            cout << (a * (x + y)) << "\n";
        else
            cout << b * min(x, y) + a * (max(x, y) - min(x, y)) << "\n";
    }
    
    return 0;   
}
