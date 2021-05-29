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
#define MAXN 1010

using namespace std;

struct Point{
    ll x, y, z;
    Point(ll _x = 0, ll _y = 0, ll _z = 0): x(_x), y(_y), z(_z){}
    ll dist(const Point &p){
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z);  
    }
};

Point p[MAXN];

int main(){
    optimize;
    
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y >> p[i].z;

    p[0] = Point(0, 0, 0);
    ll best = INFLL;

    for(int i = 1; i <= n; i++)
        best = min(best, p[0].dist(p[i]));

    cout << fixed << setprecision(3) << sqrtl(best) << "\n";

    return 0;   
}
