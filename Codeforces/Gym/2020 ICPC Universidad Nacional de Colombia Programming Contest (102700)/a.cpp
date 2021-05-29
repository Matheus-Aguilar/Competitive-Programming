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
#define fi first
#define se second
 
using namespace std;
 
typedef pair<ll, ll> pll;
typedef pair<long double, long double> pdd;
 
pll a, b, c, d;
pdd v1, v2;
long double l1, l2;
 
long double dist(pdd x, pdd y){
    return (x.fi - y.fi) * (x.fi - y.fi) + (x.se - y.se) * (x.se - y.se);
}
 
long double f(long double x){
    
    pdd p1, p2;
    
    if(x >= l1)
        p1 = b;
    else
        p1 = pdd(a.fi + x * v1.fi, a.se + x * v1.se);
 
    if(x >= l2)
        p2 = d;
    else
        p2 = pdd(c.fi + x * v2.fi, c.se + x * v2.se);
 
    //cout << x << " " << p1.fi << " " << p1.se << " " << p2.fi << " " << p2.se << "\n";\
 
    return dist(p1, p2);
}
 
long double ternarySearch(long double l, long double r){
    while(abs(r - l) >= 1e-9L){
        long double m1 = l + (r - l)/3.0, m2 = r - (r - l)/3.0;
        long double f1 = f(m1), f2 = f(m2);
 
        if(f1 > f2)
            l = m1;
        else if(f1 < f2)
            r = m2;
        else{
            l = m1;
            r = m2;
        }
 
        //cout << f1 << " " << f2 << "\n";
    }
 
    return sqrtl(f((l + r)/2.0));
}
 
void normal(pdd &v){
    long double norma = sqrtl(dist(pdd(0, 0), v));
    if(norma == 0.0) return;
    v.fi /= norma;
    v.se /= norma;
}
 
int main(){
    optimize;
 
    
    cin >> a.fi >> a.se;
    cin >> b.fi >> b.se;
    cin >> c.fi >> c.se;
    cin >> d.fi >> d.se;
    
    l1 = sqrtl(dist(a, b));
    l2 = sqrtl(dist(c, d));
 
    v1 = pll(b.fi - a.fi, b.se - a.se);
    v2 = pll(d.fi - c.fi, d.se - c.se);
 
    normal(v1);
    normal(v2);
 
    //cout << l1 << " " << l2 << "\n"; 
 
    cout << fixed << setprecision(12) << min(ternarySearch(0, min(l1, l2)), ternarySearch(min(l1, l2), max(l1, l2))) << "\n"; 
 
    return 0;   
}