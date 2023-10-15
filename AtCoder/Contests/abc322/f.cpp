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
#define MAXN 500500

using namespace std;

int n, q;
string s;

struct Node {
    int pre[2] = {0}, suf[2] = {0}, big[2] = {0};
    int tl, tr, lazy;
};

Node seg[4 * MAXN];

void combine(Node &cur, Node &l, Node &r){
    for(int i = 0; i < 2; i++){
        cur.big[i] = max(l.big[i], r.big[i]);
        cur.big[i] = max(cur.big[i], l.suf[i] + r.pre[i]);

        cur.pre[i] = l.pre[i];
        cur.suf[i] = r.suf[i];

        if(l.pre[i] == l.tr - l.tl + 1)
            cur.pre[i] += r.pre[i];
        if(r.suf[i] == r.tr - r.tl + 1)
            cur.suf[i] += l.suf[i];
    }
}

void build(int t, int tl, int tr){
    
    seg[t].tl = tl;
    seg[t].tr = tr;
    seg[t].lazy = 0;
    
    if(tl == tr){
        int pos = s[tl] - '0';
        seg[t].pre[pos] = 1;
        seg[t].suf[pos] = 1;
        seg[t].big[pos] = 1;

    } else {
        int tm = tl + (tr - tl) / 2;
        build(2 * t, tl, tm);
        build(2 * t + 1, tm + 1, tr);
        combine(seg[t], seg[2 * t], seg[2 * t + 1]);
    }
}

void push(int t){

    if(seg[t].lazy == 0)
        return;

    swap(seg[t].big[0], seg[t].big[1]);
    swap(seg[t].pre[0], seg[t].pre[1]);
    swap(seg[t].suf[0], seg[t].suf[1]);

    seg[t].lazy = 0;
    
    if(seg[t].tl != seg[t].tr){
        seg[2 * t].lazy ^= 1;
        seg[2 * t + 1].lazy ^= 1;
    }
}

void update(int t, int l, int r){
    
    push(t);
    
    if(seg[t].tl > r || seg[t].tr < l)
        return;
    if(seg[t].tl >= l && seg[t].tr <= r){
        seg[t].lazy = 1;
        push(t);
        return;
    }

    update(2 * t, l, r);
    update(2 * t + 1, l, r);

    combine(seg[t], seg[2 * t], seg[2 * t + 1]);
}

tuple<int, int, int> query(int t, int l, int r){
    
    push(t);
    
    if(seg[t].tl > r || seg[t].tr < l)
        return {0, 0, 0};
    if(seg[t].tl >= l && seg[t].tr <= r){
        return {seg[t].pre[1], seg[t].suf[1], seg[t].big[1]};
    }

    auto q1 = query(2 * t, l, r);
    auto q2 = query(2 * t + 1, l, r);

    int pre1 = get<0>(q1);
    int pre2 = get<0>(q2);
    int suf1 = get<1>(q1);
    int suf2 = get<1>(q2);
    int big1 = get<2>(q1);
    int big2 = get<2>(q2);

    int big = max(big1, big2);
    big = max(big, suf1 + pre2);

    int pre = pre1;
    int suf = suf2;

    if(pre1 == seg[2 * t].tr - seg[2 * t].tl + 1)
        pre += pre2;
    if(suf2 == seg[2 * t + 1].tr - seg[2 * t + 1].tl + 1)
        suf += suf1;

    return {pre, suf, big};
}

int main(){
    optimize;

    cin >> n >> q;
    cin >> s;

    build(1, 0, n - 1);

    while(q--){
        int c, l, r;
        cin >> c >> l >> r;

        if(c == 1)
            update(1, l - 1, r - 1);
        else {
            auto t = query(1, l - 1, r - 1);
            cout << get<2>(t) << "\n";
        }
    }
    
    return 0;   
}
