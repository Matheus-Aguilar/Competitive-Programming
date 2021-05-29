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

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        ll a[3], h, m, s, ns;
        cin >> a[0] >> a[1] >> a[2];

        h = ((a[0] / 1000000000LL) / 60) / 60;
        m = ((a[1] / 12) / 1000000000LL) / 60;
        s = (a[1] / 720) / 1000000000LL;
        ns = (a[2] / 720) % 1000000000LL;

        cout << "Case #" << t << ": " << h << " " << m << " " << s << " " << ns << "\n"; 
    }
    
    return 0;   
}
