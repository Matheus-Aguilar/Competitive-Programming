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
#define MAXN 1001001

using namespace std;

struct Segtree {
    ll seg[4 * MAXN];

    void build(int t, int tl, int tr){
        if(tl == tr){
            seg[t] = -INF;
        } else {
            int tm = tl + (tr - tl) / 2;
            build(2 * t, tl, tm);
            build(2 * t + 1, tm + 1, tr);
            seg[t] = max(seg[2 * t], seg[2 * t + 1]);
        }
    }

    void update(int t, int tl, int tr, int p, ll v){
        if(tl == tr){
            seg[t] = v;
        } else {
            int tm = tl + (tr - tl) / 2;
            if(p <= tm)
                update(2 * t, tl, tm, p, v);
            else
                update(2 * t + 1, tm + 1, tr, p, v);
            seg[t] = max(seg[2 * t], seg[2 * t + 1]);
        }
    }

    ll query(int t, int tl, int tr, int l, int r){
        if(tl > r || tr < l)
            return -INF;
        else if(l <= tl && tr <= r)
            return seg[t];
        else {
            int tm = tl + (tr - tl) / 2;
            ll q1 = query(2 * t, tl, tm, l, r);
            ll q2 = query(2 * t + 1, tm + 1, tr, l, r);
            return max(q1, q2);
        }
    }
};

Segtree seg1, seg2;

struct Job {
    int l, r;
    ll c;
    bool operator<(const Job &j){
        if(l != j.l)
            return l < j.l;
        if(r != j.r)
            return r < j.r;
        return c < j.c;
    }
};

int n, s, nxt[MAXN], aux[MAXN];
Job job[MAXN];

ll dp[MAXN];

int main(){
    optimize;

    cin >> n >> s;

    for(int i = 0; i < n; i++)
        cin >> job[i].l >> job[i].r >> job[i].c;
    
    sort(job, job + n);

    for(int i = 0; i < n; i++)
        aux[i] = job[i].l;
    
    for(int i = 0; i < n; i++)
        nxt[i] = upper_bound(aux, aux + n, job[i].r) - aux;

    seg1.build(1, 0, n - 1);
    seg2.build(1, 0, n - 1);

    ll best = 0;
    
    for(int i = n - 1; i >= 0; i--){
        
        ll gain = (job[i].r - job[i].l + 1) * s - job[i].c;

        dp[i] = gain;
        if(nxt[i] < n)
            dp[i] = max(dp[i], gain + seg1.query(1, 0, n - 1, nxt[i], n - 1));
        if(i + 1 <= nxt[i] - 1)
            dp[i] = max(dp[i], gain - (job[i].r + 1) * s + seg2.query(1, 0, n - 1, i + 1, nxt[i] - 1));
        
        best = max(best, dp[i]);
        seg1.update(1, 0, n - 1, i, dp[i]);
        seg2.update(1, 0, n - 1, i, dp[i] + job[i].l * s);
    }

    cout << best << "\n";
    
    return 0;   
}
