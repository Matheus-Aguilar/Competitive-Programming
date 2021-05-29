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
#define MAXN 1100

using namespace std;

struct Point{
    
    ll x, y;
    
    Point(ll _x = 0, ll _y = 0) : x(_x), y(_y){}
    
    bool operator<(const Point &p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator==(const Point &p) const { 
        return x == p.x && y == p.y; 
    }
    bool operator!=(const Point &p) const { 
        return x != p.x || y != p.y; 
    }
};

struct Segment{
    
    Point p1, p2;
    ll a, b; //Angular and linear coeficients

    Segment() {}
    
    Segment(const Point &_p1, const Point &_p2) : p1(_p1), p2(_p2) {
        if(p1.x != p2.x){
            a = (p2.y - p1.y) / (p2.x - p1.x);
            b = p2.y - a * p2.x;
        }
    }

    ll getY(ll x) const{
        return a * x + b;
    }
};

const Point fail = Point(INFLL, INFLL);

int n;
ll x[MAXN], y[MAXN], d[MAXN];
Segment seg[MAXN][4];

int orientation(const Point &p, const Point &q, const Point &r){
    ll det = (p.x - r.x) * (q.y - r.y) - (p.y - r.y) * (q.x - r.x);
    return (det > 0 ? 1 : (det < 0 ? -1 : 0));
}

Segment intersection(const Point &p, const Segment &s){
    //s is only one point
    if(s.p1 == s.p2){
        if(p == s.p1){
            return Segment(p, p);
        }
        else{
            return Segment(fail, fail);
        }
    }
    else{
        //The point isn't in the segment
        if(p.y < min(s.p1.y, s.p2.y) || p.y > max(s.p1.y, s.p2.y) || orientation(s.p1, s.p2, p) != 0)
            return Segment(fail, fail);
        
        //The point is in the segment
        return Segment(p, p);
    }
}

Segment intersection(const Segment &s1, const Segment &s2){
    
    if(s1.p1 == s1.p2) //s1 is a point
        return intersection(s1.p1, s2);
    if(s2.p1 == s2.p2) //s2 is a point
        return intersection(s2.p1, s1);
    
    int o1 = orientation(s1.p1, s1.p2, s2.p1) * orientation(s1.p1, s1.p2, s2.p2);
    int o2 = orientation(s2.p1, s2.p2, s1.p1) * orientation(s2.p1, s2.p2, s1.p2);

    //Segments don't intersect
    if(o1 > 0 || o2 > 0)
        return Segment(fail, fail);

    //Segments intersects in one point only
    if(s1.a != s2.a){
        
        if((s2.b - s1.b) % (s1.a - s2.a) != 0)
            return Segment(fail, fail);

        ll x = (s2.b - s1.b) / (s1.a - s2.a);

        Point p(x, s1.getY(x));

        return Segment(p, p); //The resulting segment is only one point
    }
    else{
        if(s2.p1.x <= s1.p1.x && s1.p1.x <= s2.p2.x)
            return Segment(s1.p1, s2.p2);
        else
            return Segment(s2.p1, s1.p2);
    }
}

void solve(const Segment &s0, set<Point> &ans, int pos){

    //All GPS have been checked
    if(pos == n){
        
        ans.insert(s0.p1);
        ans.insert(s0.p2);

        return;
    }
    
    for(int i = 0; i < 4; i++){

        //Points can generate repeated segments
        if(i > 0 && d[pos] == 0)
            continue;
        
        Segment inter = intersection(s0, seg[pos][i]);

        //Empty intersection (INFLL is just a flag)
        if(inter.p1.x == fail.x)
            continue;
        
        //Checks next GPS
        solve(inter, ans, pos + 1);

        //If s0 is just a point, there is no need to find more intersections
        if(s0.p1 == s0.p2)
            break;

        //Is already uncertain
        if(ans.size() > 1)
            return;
    }
}

int main(){
    optimize;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        
        cin >> x[i] >> y[i] >> d[i];
    
        Point p1(x[i] - d[i], y[i]), p2(x[i], y[i] - d[i]), p3(x[i], y[i] + d[i]), p4(x[i] + d[i], y[i]);

        seg[i][0] = Segment(p1, p2);
        seg[i][1] = Segment(p1, p3);
        seg[i][2] = Segment(p2, p4);
        seg[i][3] = Segment(p3, p4);
    }

    set<Point> ans;

    for(int i = 0; i < 4 && ans.size() <= 1; i++){

        //Points can generate repeated segments
        if(i > 0 && d[0] == 0)
            continue;

        solve(seg[0][i], ans, 1);
    }

    if(ans.size() < 1)
        cout << "impossible" << "\n";
    else if(ans.size() > 1)
        cout << "uncertain" << "\n";
    else
        cout << ans.begin()->x << " " << ans.begin()->y << "\n";

    return 0;   
}
