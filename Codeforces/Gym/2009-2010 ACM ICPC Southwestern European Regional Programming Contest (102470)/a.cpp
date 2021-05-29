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
 
int n;
pair<double, double> p[50011];
 
double dist(pair<double, double> &pos, double x){
    return (pos.first - x) * (pos.first - x) + pos.second * pos.second;
}
 
double f(double x){
    double mx = 0.0L;
    for(int i = 0; i < n; i++)
        mx = max(mx, dist(p[i], x));
    return mx;
}
 
double ternarySearch(double l, double r){
    while(abs(l - r) >= 1e-9L){
        double m1 = l + (r - l)/3.0L;
        double m2 = l + 2.0L * (r - l)/3.0L;
        double f1 = f(m1);
        double f2 = f(m2);
 
        if(f1 > f2)
            l = m1;
        else if(f1 < f2)
            r = m2;
        else{
            l = m1;
            r = m2;
        }
    }
    return l;
}
 
int main(){
    //optimize;
 
    while(scanf("%d", &n) == 1 && n){
        
        int up = 0, down = 0;
        
        double minx, maxx;

        for(int i = 0; i < n; i++){
            scanf("%lf%lf", &p[i].first, &p[i].second);
        }

        minx = p[0].first, maxx = p[0].first;
        for(int i = 1; i < n; i++){
            minx = min(minx, p[i].first);
            maxx = max(maxx, p[i].first);
        }
 
        double best = ternarySearch(minx, maxx);
 
        printf("%.9lf %.9lf\n", best, sqrt(f(best)));
    } 
    
    return 0;   
}