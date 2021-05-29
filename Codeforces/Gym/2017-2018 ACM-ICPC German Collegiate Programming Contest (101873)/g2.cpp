#include<bits/stdc++.h>
using namespace std;
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.141592653589793238462643383279502884L
#define INFLL 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define mod % 1000000007
#define ms(x, y) memset(x, y, sizeof(x))
#define all(v) v.begin(), v.end()
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
 
 
struct point{
	ll x, y;
};
 
ll area(const vector<point>& fig) {
    ll res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return abs(res);
}
 
ll getCount(point p, point q) 
{ 
    // If line joining p and q is parallel to 
    // x axis, then count is difference of y 
    // values 
    if (p.x == q.x) 
        return abs(p.y - q.y) - 1; 
  
    // If line joining p and q is parallel to 
    // y axis, then count is difference of x 
    // values 
    if (p.y == q.y) 
        return abs(p.x - q.x) - 1; 
  
    return __gcd(abs(p.x - q.x), abs(p.y - q.y))-1; 
}
 
 
int main(){
    optimize;
    
    int n;
    cin >> n;
    vector<point> fig(n);
    for(int i = 0; i < n; i++){
    	cin >> fig[i].x >> fig[i].y;
    }
 
    // 2S - B -+ 2 = 2I
 
    ll B = n;

    for(int i = 0; i < n - 1; i++)
    	B += getCount(fig[i], fig[i + 1]);

    B += getCount(fig[0], fig[n - 1]);

    ll S = area(fig);

    cout << (S - B + 2)/2 << "\n";
}