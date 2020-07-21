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

int segMin[4 * MAXN];
int segMax[4 * MAXN];
int valMin[MAXN];
int valMax[MAXN];

int combine(int a, int b, bool isMax){
    if(a == -1) return b;
    if(b == -1) return a;
    if(isMax) return (valMax[a] > valMax[b] ? a : b);
    return (valMin[a] < valMin[b] ? a : b);
}

void build(int node, int tl, int tr){
    if(tl == tr){
        segMin[node] = segMax[node] = tl;
    }
    else{
        int tm = tl + (tr - tl)/2;
        build(2 * node, tl, tm);
        build(2 * node + 1, tm + 1, tr);
        segMin[node] = combine(segMin[2 * node], segMin[2 * node + 1], false);
        segMax[node] = combine(segMax[2 * node], segMax[2 * node + 1], true);
    }
}

void update(int node, int tl, int tr, int i, int p){
    if(tl == tr){
        valMin[tl] = min(valMin[tl], p);
        valMax[tl] = max(valMax[tl], p);
    }
    else{
        int tm = tl + (tr - tl)/2;
        if(i <= tm)
            update(2 * node, tl, tm, i, p);
        else
            update(2 * node + 1, tm + 1, tr, i, p);
        segMin[node] = combine(segMin[2 * node], segMin[2 * node + 1], false);
        segMax[node] = combine(segMax[2 * node], segMax[2 * node + 1], true);
    }
}

pii query(int node, int tl, int tr, int l, int r){
    if(l > r)
        return make_pair(-1, -1);
    if(tl == l && tr == r)
        return make_pair(segMin[node], segMax[node]);
    int tm = tl + (tr - tl)/2;
    pii left = query(2 * node, tl, tm, l, min(tm, r));
    pii right = query(2 * node + 1, tm + 1, tr, max(tm + 1, l), r);
    return make_pair(combine(left.fi, right.fi, false), combine(left.se, right.se, true));
}

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> valMin[i];
        valMax[i] = valMin[i];
    }

    build(1, 0, n - 1);

    while(m--){
        int op;
        cin >> op;
        if(op  == 1){
            int p, i;
            cin >> p >> i;
            update(1, 0, n - 1, i - 1, p);
        }
        else{
            int l, r;
            cin >> l >> r;
            --l, --r;

            pii best, left, right, comb;
            best = query(1, 0, n - 1, l, r);

            if(best.fi != best.se){
                cout << valMax[best.se] - valMin[best.fi] << "\n";
            }
            else{
                left = query(1, 0, n - 1, l, best.fi - 1);
                right = query(1, 0, n - 1, best.fi + 1, r);
                comb = make_pair(combine(left.fi, right.fi, false), combine(left.se, right.se, true));
                cout << max(valMax[best.se] - valMin[comb.fi], valMax[comb.se] - valMin[best.fi]) << "\n";
            }
        }
    }
    
    return 0;   
}
