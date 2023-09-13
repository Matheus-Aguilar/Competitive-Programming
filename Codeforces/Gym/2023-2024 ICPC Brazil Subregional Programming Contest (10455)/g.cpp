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
    int id;

    Point() {}
    Point(ll _x, ll _y) : x(_x), y(_y) {}

    bool operator<(const Point &p) const {
        if(x != p.x)
            return x < p.x;
        return y < p.y;
    }

    Point operator-(const Point &p) {
        return Point(x - p.x, y - p.y);
    }
};

ll cross(Point p1, Point p2){
    return p1.x * p2.y - p1.y * p2.x;
}

int orientation(Point p, Point q, Point r){
    ll sign = cross(p - r, q - r);
    return (sign > 0 ? 1 : (sign < 0 ? -1 : 0));
}

vector<Point> convexHull(vector<Point> &p){
    
    sort(all(p));

    Point A = p[0];
    Point B = p.back();

    int n = p.size();
    vector<Point> hull(n * 2);

    // Upper hull
    int k = 0;
    hull[k++] = A;

    for(int i = 1; i < n; i++){
        if(i == n - 1 || orientation(A, B, p[i]) >= 0){
            while(k >= 2 && orientation(hull[k - 2], p[i], hull[k - 1]) < 0)
                k--;
            hull[k++] = p[i];
        }
    }

    // Lower hull
    int t = k;
    hull[k++] = A;

    for(int i = 1; i < n; i++){
        if(i == n - 1 || orientation(A, B, p[i]) <= 0){
            while(k - t >= 2 && orientation(hull[k - 2], p[i], hull[k - 1]) > 0)
                k--;
            hull[k++] = p[i];
        }
    }

    // Remove repeated B point
    k--;

    // Reverse lower hull
    reverse(hull.begin() + t, hull.begin() + k);

    // Resize hull
    hull.resize(k);

    // All collinear degenerate case)
    if(hull.size() > n + 1){
        return p;
    }

    // Remove repeated A point
    hull.pop_back();

    return hull;
}

int main(){
    optimize;

    int n;
    cin >> n;

    vector<Point> p(n);

    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
        p[i].id = i + 1;
    }

    vector<Point> hull = convexHull(p);

    vector<int> ids(hull.size());

    for(int i = 0; i < hull.size(); i++)
        ids[i] = hull[i].id;
    
    sort(all(ids));

    for(int i = 0; i < ids.size(); i++)
        cout << ids[i] << " \n"[i+1==ids.size()];
    
    return 0;   
}
