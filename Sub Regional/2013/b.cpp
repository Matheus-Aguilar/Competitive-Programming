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
    Point(ll _x = -1, ll _y = -1) : x(_x), y(_y){}
    Point(const Point &o){ x = o.x, y = o.y; }
    bool operator<(const Point &o){ return x < o.x; }
    bool operator==(const Point &o){ return x == o.x && y == o.y; }
    Point operator+(const Point &o){ return Point(x + o.x, y + o.y); }
    Point operator-(const Point &o){ return Point(x - o.x, y - o.y); }
    ll operator^(const Point &o){ return x * o.y - o.x * y; }
};

istream & operator>>(istream &in, Point &p){
    in >> p.x >> p.y;
    return in;
}

ostream & operator<<(ostream &out, const Point &p){
    out << p.x << " " << p.y;
    return out;
}

vector<pair<Point, Point>> segments;
struct cmp{
    bool operator()(int a, int b){
        Point a1 = segments[a].first;
        Point a2 = segments[a].second;
        Point b1 = segments[b].first;
        Point b2 = segments[b].second;

        if(a1.x < b1.x) return ((a1 - b1) ^ (a2 - b1)) > 0;
        return ((b1 - a1) ^ (b2 - a1)) < 0 ;
    }
};

struct Event{
    Point p;
    int id, type;
    Event(const Point &_p = Point(), int _id = -1, int _type = -1): p(_p), id(_id), type(_type){}
    bool operator<(const Event &o){
        if(p.x != o.p.x) return p.x < o.p.x;
        if(type != o.type) return type < o.type;
        return p.y < o.p.y;
    }
};

vector<Event> events;
set<int, cmp> activeEvents;

vector<int> query;
vector<Point> dp;

vector<int> up;
vector<int> lowest;

void solve(){
    set<int, cmp>::iterator it;
    activeEvents.insert(events[0].id);

    for(int i = 1; i < events.size(); i++){
        
        int id = events[i].id;
        int type = events[i].type;
        
        if(type == 0){ //Evento de entrada
            activeEvents.insert(id);
            if(segments[id].first.y > segments[id].second.y){
                it = activeEvents.find(id);
                up[id] = *(++it);
            }
        }
        else if(events[i].type == 2){ //Evento de saida
            if(segments[id].first.y < segments[id].second.y){
                it = activeEvents.find(id);
                up[id] = *(++it);
            }
            activeEvents.erase(id);
        }
        else{ //Evento de query
            lowest[id] = *(activeEvents.begin());
        }
    }
}

Point climb(int x, int id){
    if(segments[id].first.y == segments[id].second.y)
        return Point(x, segments[id].first.y);
    if(dp[id] == Point()){
        int nextX = (segments[id].first.y > segments[id].second.y ? segments[id].first.x : segments[id].second.x);
        dp[id] = climb(nextX, up[id]);
    }
    return dp[id];
}

int main(){
    optimize;

    int n, c;
    while(cin >> n >> c){
        segments.resize(n + 1);
        events.resize(2 * n + c + 2);
        query.resize(c);
        dp.assign(n + 1, Point());
        up.resize(n);
        lowest.resize(c);

        for(int i = 0; i < n; i++){
            cin >> segments[i].first >> segments[i].second;
            if(segments[i].second < segments[i].first)
                swap(segments[i].first, segments[i].second);
            events[2 * i] = Event(segments[i].first, i, 0);
            events[2 * i + 1] = Event(segments[i].second, i, 2);
        }

        segments[n] = make_pair(Point(-1, INF), Point(INF, INF));
        events[2 * n] = Event(Point(-1, INF), n, 0);
        events[2 * n + 1] = Event(Point(INF, INF), n, 2);

        for(int i = 0; i < c; i++){
            cin >> query[i];
            events[2 * n + i + 2] = Event(Point(query[i], 0), i, 1);
        }

        sort(all(events));
        solve();

        for(int i = 0; i < c; i++){
            if(lowest[i] == n + 1)
                cout << query[i] << "\n";
            else{
                Point p = climb(query[i], lowest[i]);
                if(p.y == INF)
                    cout << p.x << "\n";
                else
                    cout << p << "\n";
            }
        }
    }

    return 0;   
}
