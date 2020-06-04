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
        ll a, b;
        cin >> a >> b;
        
        if(a < b){
            ll cont = 0;
            while(a < b){
                a <<= 1;
                cont++;
            }
            if(a == b)
                cout << cont/3 + (cont % 3 ? 1 : 0) << "\n";
            else
                cout << -1 << "\n";
        }
        else{
            ll cont = 0;
            while(a > b){
                if(a & 1) break;
                a >>= 1;
                cont++;
            }
            if(a == b)
                cout << cont/3 + (cont % 3 ? 1 : 0) << "\n";
            else
                cout << -1 << "\n";
        }
    }
    
    return 0;   
}
