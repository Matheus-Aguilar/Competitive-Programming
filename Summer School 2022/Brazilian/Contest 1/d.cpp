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

struct Point {
    ll x, y;
    Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    ll operator^(const Point &p){
        return (x * p.y) - (y * p.x);
    }
};

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--) {
        
        int n;
        
        ll w;
        double perc, add, sub;

        cin >> n;

        vector<Point> p(n);

        for(int i = 0; i < n; i++){
            cin >> p[i].x >> p[i].y;
        }

        cin >> w;
        cin >> perc >> sub >> add;

        double vol = 0.0, cur;

        for(int i = 0; i < n - 1; i++){
            vol += (p[i] ^ p[i + 1]);
        }

        vol += (p[n - 1] ^ p[0]);
        
        vol = abs(vol);
        vol /= 2.0;

        vol *= w;

        cur = (vol * perc) / 100.0;

        cur -= sub;

        if(cur < 0) {
            cout << "Lack of water. ";
            cur = 0.0;
        }

        cur += add;
        

        if(cur > vol) {
            cout << "Excess of water. ";
            cur = vol;
        }

        ll ans = (cur / vol) * 100.0;

        cout << "Final percentage: " << ans << "%\n";
    }
    
    return 0;   
}
