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
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        if(max(x, a - n) < max(y, b - n)){
            if(a - x > n){
                a -= n;
                n -= n;
            }
            else{
                n -= a - x;
                a -= a - x;
            }

            if(b - y > n){
                b -= n;
                n -= n;
            }
            else{
                n -= b - y;
                b -= b - y;
            }
        }
        else{
            if(b - y > n){
                b -= n;
                n -= n;
            }
            else{
                n -= b - y;
                b -= b - y;
            }

            if(a - x > n){
                a -= n;
                n -= n;
            }
            else{
                n -= a - x;
                a -= a - x;
            }
        }

        cout << a * b << "\n";
    }

    return 0;   
}
