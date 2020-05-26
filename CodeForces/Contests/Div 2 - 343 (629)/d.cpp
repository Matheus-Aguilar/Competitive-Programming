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

using namespace std;

ll seg[4 * MAXN];

map<ll, int> m;

vector<ll> v;
vector<ll> aux;

void update(int node, int tl, int tr, int pos, ll val){
    if(tl == tr)
        seg[node] = val;
    else{
        int tm = tl + (tr - tl)/2;
        if(pos <= tm)
            update(2 * node, tl, tm, pos, val);
        else
            update(2 * node + 1, tm + 1, tr, pos, val);
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }
}

ll query(int node, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    else if(tl == l && tr == r)
        return seg[node];
    else{
        int tm = tl + (tr - tl)/2;
        return max(
            query(2 * node, tl, tm, l, min(tm, r)),
            query(2 * node + 1, tm + 1, tr, max(tm + 1, l), r)
        );
    }
}

int main(){
    optimize;

    int n;
    cin >> n;

    v.resize(n);

    for(int i = 0; i < n; i++){
        ll r, h;
        cin >> r >> h;
        v[i] = r * r * h;
    }

    aux = v;
    sort(all(aux));

    for(int i = 0; i < n; i++)
        m[aux[i]] = i;

    for(int i = 0; i < n; i++)
        update(1, 0, n - 1, m[v[i]], v[i] + query(1, 0, n - 1, 0, m[v[i]] - 1));

    cout << fixed << setprecision(9) << PI * query(1, 0, n - 1, 0, n - 1) << "\n";

    return 0;   
}
