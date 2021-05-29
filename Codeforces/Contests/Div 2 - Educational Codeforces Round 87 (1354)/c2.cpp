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
        int n;
        cin >> n;
        n *= 2;

        long double t = (2.0L * PI)/n;
        long double r = 1.0L/(2.0L * sin(t/2));

        long double y1 = r * cos(t/4re), y2 = r * cos(t/4 + PI);

        cout << fixed << setprecision(9) << abs(y2 - y1) << "\n";
    }

    return 0;   
}
