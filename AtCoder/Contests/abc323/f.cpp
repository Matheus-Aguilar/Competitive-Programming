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

ll dist(ll xa, ll ya, ll xb, ll yb){
    return abs(xa - xb) + abs(ya - yb);
}

ll solve(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc){
    
    ll total = 0;

    if(xb > xc){
        total += dist(xa, ya, xb + 1, yb);
        total += dist(xb, yb, xc, yb);

        xb = xc;
        xa = xb + 1;
        ya = yb;
    } else if(xb < xc){
        total += dist(xa, ya, xb - 1, yb);
        total += dist(xb, yb, xc, yb);

        xb = xc;
        xa = xb - 1;
        ya = yb;
    } else {
        if(yb > yc){
            total += dist(xa, ya, xb, yb + 1);    

            if(xa == xb && xa == xc && ya < yb){
                total += 2;
            }

            xa = xb;
            ya = yb + 1;
        } else {
            total += dist(xa, ya, xb, yb - 1);

            if(xa == xb && xa == xc && ya > yb){
                total += 2;
            }
            
            xa = xb;
            ya = yb - 1;
        }
    }

    if(ya == yb)
        total += 2;
    
    total += dist(xb, yb, xc, yc);

    return total;
}

int main(){
    optimize;

    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    cout << min(solve(xa, ya, xb, yb, xc, yc), solve(ya, xa, yb, xb, yc, xc)) << "\n";
    
    return 0;   
}
