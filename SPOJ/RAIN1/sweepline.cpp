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
#define MAXN 41000

using namespace std;

struct Point{
    ll x, y;
    int i, t;
    Point(ll _x = -1, ll _y = -1, int _i = -1, int _t = -1){ x = _x, y = _y, i = _i, t = _t; }
    Point(const Point &o){ x = o.x, y = o.y, i = o.i, t = o.t; }
    Point operator+(const Point &o){ return Point(x + o.x, y + o.y); }
    Point operator-(const Point &o){ return Point(x - o.x, y - o.y); }
    ll operator^(const Point &o){ return x * o.y - y * o.x; }
    bool operator<(const Point &o){ 
        if(x != o.x) return x < o.x;
        if(t != o.t) return t < o.t;
        return (t ? y > o.y : y < o.y); 
    }
};

istream & operator>>(istream &in, Point &p){
    in >> p.x >> p.y;
    return in;
}

int n;
pair<Point, Point> seg[MAXN];
Point event[2 * MAXN];
int deg[MAXN];
int lit[MAXN];
int down[MAXN];

struct cmp{
    bool operator()(const int &a, const int &b){
        Point a1 = seg[a].first, a2 = seg[a].second, b1 = seg[b].first, b2 = seg[b].second;
        if(a1.x < b1.x) return ((a1 - b1)^(a2 - b1)) < 0;
        return ((b1 - a1)^(b2 - a1)) > 0;
    }
};

set<int, cmp> active;
set<int, cmp>::iterator it;

void sweepline(){
    active.insert(event[0].i);
    for(int i = 1; i < 2 * n + 1; i++){
        
        int id = event[i].i, type = event[i].t;
        Point p1 = seg[id].first, p2 = seg[id].second;
        
        int highest = *(active.begin());
        lit[highest] += event[i].x - event[i - 1].x;
        
        if(type == 0){
            active.insert(id);
            if(p1.y < p2.y){
                it = active.find(id);
                down[id] = *(++it);
                deg[*it]++;
            }
        }
        else{
            if(p1.y > p2.y){
                it = active.find(id);
                down[id] = *(++it);
                deg[*it]++;
            }
            active.erase(id);
        }
    }
    active.erase(event[2 * n + 1].i);
    down[n] = n;
}

void toposort(){
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(deg[i] == 0)
            q.push(i);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        lit[down[cur]] += lit[cur];
        deg[down[cur]]--;
        if(deg[down[cur]] == 0) q.push(down[cur]);
    }
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        
        memset(deg, 0, sizeof(int) * (n + 1));
        memset(lit, 0, sizeof(int) * (n + 1));
        
        for(int i = 0; i < n; i++){
            cin >> seg[i].first >> seg[i].second;
            event[2 * i] = Point(seg[i].first.x, seg[i].first.y, i, 0);
            event[2 * i + 1] = Point(seg[i].second.x, seg[i].second.y, i, 1);
        }

        seg[n] = make_pair(Point(-1, -1, n, 0), Point(INF, -1, n, 1));
        event[2 * n] = Point(seg[n].first.x, seg[n].first.y, n, 0);
        event[2 * n + 1] = Point(seg[n].second.x, seg[n].second.y, n, 1);
        
        sort(event, event + 2 * n + 2);
        sweepline();
        toposort();

        for(int i = 0; i < n; i++)
            cout << lit[i] << "\n";
    }
    return 0;   
}
