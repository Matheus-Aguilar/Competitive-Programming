#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<long long int, long long int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define fi first
#define se second
 
using namespace std;
 
pii operator-(const pii &a, const pii &b){
    pii c = make_pair(a.fi - b.fi, a.se - b.se);
    return c;
}
 
ll cross(pii a, pii b){
    return a.fi * b.se - a.se * b.fi;
}
 
ll dist(pii a, pii b){
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}
 
int main(){
    optimize;
 
    int n;
    cin >> n;
 
    int a = 0, b = -1, c = -1;
 
    vector<pii> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].fi >> p[i].se;
    } 
    for(int i = 1; i < n; i++){
        if(b == -1 || dist(p[a], p[i]) < dist(p[a], p[b]))
            b = i;
    }
    for(int i = 1; i < n; i++){
        if(i == b) 
            continue;
        ll area = abs(cross(p[b] - p[a], p[i] - p[a]));
        if(area && (c == -1 || abs(cross(p[b] - p[a], p[c] - p[a])) > area))
            c = i;
    }
 
    cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
 
    return 0;   
}