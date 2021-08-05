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

struct PT {
  ll x, y;
  PT(ll x = 0, ll y = 0) : x(x), y(y) {}
  PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
  PT operator * (ll c) const { return PT(x*c, y*c); }
  PT operator / (ll c) const { return PT(x/c, y/c); }
  bool operator==(const PT &p) const { return x == p.x && y == p.y; }
};

ll dot (PT p, PT q) { return p.x * q.x + p.y*q.y; }
ll cross (PT p, PT q) { return p.x * q.y - p.y*q.x; }

bool ptInSegment (PT a, PT b, PT c) {
  if (a == b) return a == c;
  a = a-c, b = b-c;
  return cross(a, b) == 0 && dot(a, b) <= 0;
}

bool ptInsideTriangle(PT p, PT a, PT b, PT c) {
  if(cross(b-a, c-b) < 0) swap(a, b);
  if(ptInSegment(a,b,p)) return 1;
  if(ptInSegment(b,c,p)) return 1;
  if(ptInSegment(c,a,p)) return 1;
  bool x = cross(b-a, p-b) < 0;
  bool y = cross(c-b, p-c) < 0;
  bool z = cross(a-c, p-a) < 0;
  return x == y && y == z;
}

bool pointInConvexPolygon(const vector<PT> &p, PT q) {
  if (p.size() == 1) return p.front() == q;
  int l = 1, r = p.size()-1;
  while(abs(r-l) > 1) {
    int m = (r+l)/2;
    if(cross(p[m]-p[0] , q-p[0]) < 0) r = m;
    else l = m;
  }
  return ptInsideTriangle(q, p[0], p[l], p[r]);
}

int main(){
    optimize;
    
    int s, r, m;
    cin >> s >> r >> m;

    vector<PT> ps(s), pr(r), pm(m);

    for(int i = 0; i < s; i++)
        cin >> ps[i].x >> ps[i].y;
    
    for(int i = 0; i < r; i++)
        cin >> pr[i].x >> pr[i].y;
    
    for(int i = 0; i < m; i++)
        cin >> pm[i].x >> pm[i].y;

    int n;
    cin >> n;

    vector<PT> q(n);

    for(int i = 0; i < n; i++){
        cin >> q[i].x >> q[i].y;
    }

    for(int i = 0; i < n; i++){
        if(pointInConvexPolygon(ps, q[i])){
            cout << "Sheena" << "\n";
        }
        else if(pointInConvexPolygon(pr, q[i])){
            cout << "Rose" << "\n";
        }
        else if(pointInConvexPolygon(pm, q[i])){
            cout << "Maria" << "\n";
        }
        else{
            cout << "Outside" << "\n";
        }
    }

    return 0;   
}
