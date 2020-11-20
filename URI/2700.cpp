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
#define MAXN 100010

using namespace std;

struct Person{
    
    ll b, f, d;

    Person(ll _b = 0, ll _f = 0, ll _d = 0): b(_b), f(_f), d(_d){}

    bool operator<(const Person &p) const {
        if(b != p.b) return b < p.b;
        return f > p.f;
    }
};

int n;
ll bit[MAXN], f[MAXN], d[MAXN], u[MAXN];
Person p[MAXN];

void update(int x, ll v){
    while(x <= n){
        bit[x] = max(bit[x], v);
        x += -x & x;
    }
}

ll query(int x){
    ll ans = 0;
    while(x > 0){
        ans = max(ans, bit[x]);
        x -= -x & x;
    }
    return ans;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> p[i].b >> p[i].f >> p[i].d;

    sort(p, p + n);

    for(int i = 0; i < n - 1; i++){
        if(p[i].b == p[i + 1].b && p[i].f == p[i + 1].f){
            p[i + 1].d += p[i].d;
            p[i].d = 0;
        }
        f[i] = p[i].f;
        d[i] = p[i].d;
    }

    f[n - 1] = p[n - 1].f;
    d[n - 1] = p[n - 1].d;

    for(int i = 0; i < n; i++)
        u[i] = f[i];

    sort(u, u + n);
    int m = unique(u, u + n) - u;

    for(int i = 0; i < n; i++){

        int x = lower_bound(u, u + m, f[i]) - u;

        ll best = query(x);
        update(x + 1, best + d[i]);
    }

    cout << query(m) << "\n";

    return 0;   
}
