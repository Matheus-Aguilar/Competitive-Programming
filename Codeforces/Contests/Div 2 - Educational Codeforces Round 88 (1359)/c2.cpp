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
 
ll h, c, t;
 
int main(){
    optimize;
 
    int T;
    cin >> T;
    while(T--){
        cin >> h >> c >> t;
        if(t >= h)
            cout << 1 << "\n";
        else if(t <= (h + c)/2)
            cout << 2 << "\n";
        else{
            ll k = (h - t)/(2 * t - h - c);
            ll ans;
            long double op1 = abs((1.0L * h * k + c * k + h)/(2.0L * k + 1) - t);
            long double op2 = abs((1.0L * h * (k + 1) + c * (k + 1) + h)/(2.0L * k + 3) - t);
            
            ans = (op1 <= op2 ? 2 * k + 1 : 2 * k + 3);
            
            long double op3 = abs((1.0L * h * (k - 1) + c * (k - 1) + h)/(2.0L * k - 1) - t);
            if(k > 0)
                ans = (op3 < op2 && op3 < op1 ? 2 * k - 1 : ans);
            
            cout << ans << "\n";
        }
    }
    
    return 0;   
}