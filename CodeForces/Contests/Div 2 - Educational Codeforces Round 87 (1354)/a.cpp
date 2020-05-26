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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a -= b;

        if(a <= 0)
            cout << b << "\n";
        else if(c - d <= 0)
            cout << -1 << "\n";
        else
            cout << ((a + c - d - 1)/(c - d)) * c + b << "\n";
    }

    return 0;   
}
