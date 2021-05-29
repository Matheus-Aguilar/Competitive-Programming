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
    int x, y;
    char p;
    
    Point(int _x = 0, int _y = 0, char _p = 0) : x(_x), y(_y), p(_p){}
};

bool cmpX(const Point &a, const Point &b){
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.p < b.p;
}

bool cmpY(const Point &a, const Point &b){
    if(a.y != b.y) return a.y < b.y;
    if(a.x != b.x) return a.x < b.x;
    return a.p < b.p;
}

int main(){
    optimize;

    int n, best = 0, tb = 0, tw = 0;
    cin >> n;

    vector<Point> p(n);

    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y >> p[i].p;
    
        if(p[i].p == 'b')
            tb++;
        else
            tw++;
    }

    sort(all(p), cmpX);
    
    for(int i = 0, b = 0, w = 0; i < n; i++){
        
        if(p[i].p == 'b')
            b++;
        else
            w++;
    
        if(i == n - 1 || p[i].x != p[i + 1].x){
            best = max(best, b + tw - w);
            best = max(best, w + tb - b);
        }
    }

    sort(all(p), cmpY);
    
    for(int i = 0, b = 0, w = 0; i < n; i++){
        
        if(p[i].p == 'b')
            b++;
        else
            w++;
    
        if(i == n - 1 || p[i].y != p[i + 1].y){
            best = max(best, b + tw - w);
            best = max(best, w + tb - b);
        }
    }

    cout << best << "\n";

    return 0;
}
