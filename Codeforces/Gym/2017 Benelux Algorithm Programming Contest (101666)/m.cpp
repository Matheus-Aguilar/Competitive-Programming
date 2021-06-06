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
#define MAXN 100100
#define fi first
#define se second

using namespace std;

int n, m = 0, st[MAXN], c = 0;
pii h, w, p[MAXN];

bool inside(int x, int y){
    if(x < min(h.fi, w.fi) || x > max(h.fi, w.fi))
        return false;
    if(y < min(h.se, w.se) || y > max(h.se, w.se))
        return false;
    return true;
}

int main(){
    optimize;

    cin >> n;

    cin >> h.fi >> h.se;
    cin >> w.fi >> w.se;

    for(int i = 0; i < n; i++){
        
        int x, y;
        cin >> x >> y;
    
        if(inside(x, y))
            p[m++] = make_pair(x, y);
    }

    if(h.fi > w.fi){
        h.fi *= -1;
        w.fi *= -1;
        for(int i = 0; i < m; i++) p[i].fi *= -1;
    }

    if(h.se > w.se){
        h.se *= -1;
        w.se *= -1;
        for(int i = 0; i < m; i++) p[i].se *= -1;
    }

    sort(p, p + m);

    for(int i = 0; i < m; i++){

        int pos = upper_bound(st, st + c, p[i].se) - st;

        if(pos == c)
            st[c++] = p[i].se;
        else
            st[pos] = p[i].se;
    }

    cout << c << "\n";

    return 0;   
}
