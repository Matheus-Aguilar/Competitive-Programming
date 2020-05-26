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
#define MAXN 1000010
 
using namespace std;
 
int seg[4 * MAXN];
 
void build(int node, int tl, int tr){
    if(tl == tr)
        seg[tl] = 0;
    else{
        int tm = tl + (tr - tl)/2;
        build(2 * node, tl, tm);
        build(2 * node + 1, tm + 1, tr);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
}
 
void update(int node, int tl, int tr, int pos, int add){
    if(tl == tr)
        seg[node] += add;
    else{
        int tm = tl + (tr - tl)/2;
        if(pos <= tm)
            update(2 * node, tl, tm, pos, add);
        else
            update(2 * node + 1, tm + 1, tr, pos, add);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
}
 
int query(int node, int tl, int tr, int k){
    if(tl == tr) 
        return tl;
    int tm = tl + (tr - tl)/2;
    return (seg[2 * node] >= k ? query(2 * node, tl, tm, k) : query(2 * node + 1, tm + 1, tr, k - seg[2 * node]));
}
 
int main(){
    optimize;
 
    int n, q, x;
    cin >> n >> q;
 
    build(1, 0, n);
    for(int i = 0; i < n; i++){
        cin >> x;
        update(1, 0, n, x, 1);
    }
 
    while(q--){
        cin >> x;
        if(x > 0)
            update(1, 0, n, x, 1);
        else{
            int pos = query(1, 0, n, -x);
            update(1, 0, n, pos, -1);
        }
    }
 
    cout << (seg[1] ? query(1, 0, n, 1) : 0) << "\n";
    
    return 0;   
}