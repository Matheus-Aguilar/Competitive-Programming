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
    Point() {}
    Point(ll _x, ll _y) : x(_x), y(_y) {}
    const Point operator-(const Point &p){
        return Point(x - p.x, y - p.y);
    }
    ll operator^(const Point &p){
        return x * p.y - y * p.x;
    }
};

ll getArea(vector<Point> &pol){
    ll area = 0;
    for(int i = 0; i < pol.size(); i++){
        area += (pol[i] ^ pol[(i + 1) % pol.size()]);
    }
    return abs(area);
}

int main(){
    optimize;

    int n;
    cin >> n;

    ll area = 0;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        vector<Point> pol(k);
        for(int j = 0; j < k; j++){
            cin >> pol[j].x >> pol[j].y;
        }
        area += getArea(pol);
    }

    cout << area / 2 << "\n";
    
    return 0;   
}
