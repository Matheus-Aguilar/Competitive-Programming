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
#define MAXN 200100

using namespace std;

int n, q;

pii seg[4 * MAXN];
pii g[MAXN];

pii combine(pii a, pii b){
    return make_pair(max(a.first, b.first), min(a.second, b.second));
}

void build(int node, int tl, int tr){
    if(tl == tr){
        seg[node] = g[tl];
    }
    else{

        int tm = tl + (tr - tl)/2;

        build(2 * node, tl, tm);
        build(2 * node + 1, tm + 1, tr);

        seg[node] = combine(seg[2 * node], seg[2 * node + 1]);
    }
}

void update(int node, int tl, int tr, int pos, pii p){
    if(tl == tr){
        seg[node] = p;
    }
    else{

        int tm = tl + (tr - tl)/2;

        if(pos <= tm)
            update(2 * node, tl, tm, pos, p);
        else
            update(2 * node + 1, tm + 1, tr, pos, p);

        seg[node] = combine(seg[2 * node], seg[2 * node + 1]);
    }
}

pii query(int node, int tl, int tr, int l, int r){
    if(l > r){
        return make_pair(-INF, INF);
    }
    else if(l == tl && r == tr){
        return seg[node];
    }
    else{
        int tm = tl + (tr - tl)/2;

        return combine(
            query(2 * node, tl, tm, l, min(tm, r)),
            query(2 * node + 1, tm + 1, tr, max(tm + 1, l), r)
        );
    }
}

void update(int i, int l, int r){
    pii range = make_pair(l, r);
    update(1, 0, n - 1, i - 1, range);
}

int query(int l, int r){
    pii range = query(1, 0, n - 1, l - 1, r - 1);
    return max(range.second - range.first + 1, 0);
}

int main(){
    optimize;

    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> g[i].first >> g[i].second;

    build(1, 0, n - 1);

    while(q--){
        char op;
        cin >> op;

        if(op == 'C'){
            
            int i, l, r;
            cin >> i >> l >> r;
            
            update(i, l, r);
        }
        else{

            int l, r;
            cin >> l >> r;

            cout << query(l, r) << "\n";
        }
    }
    
    return 0;   
}
