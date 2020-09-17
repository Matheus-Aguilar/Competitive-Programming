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

struct Point{
    ll x, y;
    Point(ll _x = 0, ll _y = 0) : x(_x), y(_y){}
    Point operator+(const Point &p) const{
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point &p) const{
        return Point(x - p.x, y - p.y);
    }
    ll operator^(const Point &p) const{
        return x * p.y - p.x * y;
    }
};

int main(){
    optimize;

    int n;
    cin >> n;

    vector<Point> p(n);
    
    ll best = INFLL;

    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    
    for(int i = 0; i < n; i++){
        Point a = p[i] - p[(i + 1) % n];
        Point b = p[(i + 1) % n] - p[(i + 2) % n];
        best = min(best, abs(a ^ b));
    }

    cout << best << "\n";

    return 0;   
}
