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

    ll cont = 0, r, d;
    cin >> r >> d;

    //|sqrt(x^2 + y^2) - r| <= D
    
    //sqrt(x^2 + y^2) - r <= D
    //sqrt(x^2 + y^2) <= D + r
    //x^2 + y^2 <= (D + r)^2
    //y^2 <= (D+r)^2 - x^2
    //y >= -sqrt && y <= sqrt

    //-sqrt(x^2+y^2) + r <= D
    //-sqrt(x^2+y^2) <= D - r
    //sqrt(x^2+y^2) >= r - D
    //x^2+y^2 >= (r - d)^2
    //y^2 >= (r - d)^2 - x^2
    //y <= -sqrt ou y >= sqrt

    for(ll x = -r - d; x <= r + d; x++){
        
        ll y1 = 0, y2;
        
        if((r - d) * (r - d) - x * x >= 0 && d <= r)
            y1 = ceil(sqrt((r - d) * (r - d) - x * x));
        
        y2 = floor(sqrt((d + r) * (d + r) - x * x));

        cont += 2 * (y2 - y1 + 1);

        if(y1 == 0)
            cont--;
    }

    cout << cont << "\n";
    
    return 0;   
}
