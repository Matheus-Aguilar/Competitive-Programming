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

const long double r = 0.916297857297023;

int main(){
    optimize;
    
    int xp, yp, xd, yd;
    cin >> xp >> yp >> xd >> yd;
    cout << fixed << setprecision(15) << ((xp - xd) * (xp - xd) + (yp - yd) * (yp - yd)) * r << "\n";

    return 0;   
}
