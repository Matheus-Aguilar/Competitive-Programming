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

ll segtree[4 * MAXN];

void build(int node, int start, int end){
    if(start == end){
        segtree[node] = 1;
    }
    else{
        int middle = start + (end - start)/2;
        build(2 * node, start, middle);
        build(2 * node + 1, middle + 1, end);
        segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
    }
}

void update(int node, int start, int end, int p, int val){
    if(start == end){
        segtree[node] = val;
    }
    else{
        int middle = start + (end - start)/2;
        if(p <= middle)
            update(2 * node, start, middle, p, val);
        else
            update(2 * node + 1, middle + 1, end, p, val);
        segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
    }
}

ll query(int node, int start, int end, int l, int r){
    if(l > r){
        return 0;
    }
    else if(start == l && end == r){
        return segtree[node];
    }
    else{
        int middle = start + (end - start)/2;
        return 
            query(2 * node, start, middle, l, min(r, middle)) +
            query(2 * node + 1, middle + 1, end, max(l, middle + 1), r);
    }
}

ll solve(vector<pii> &a){

    int n = a.size();
    ll sum = 0;

    vector<pii> in(n);
    vector<pii> out(n);
    vector<int> end(n);

    for(int i = 0; i < n; i++){
        in[i] = pii(a[i].first, i);
        out[i] = pii(a[i].second, i);
    }

    sort(all(in));
    sort(all(out));

    for(int i = 0; i < n; i++)
        end[out[i].second] = i;

    build(1, 0, n - 1);

    for(int i = 0; i < n; i++){
        update(1, 0, n - 1, end[in[i].second], 0);
        sum += query(1, 0, n - 1, 0, end[in[i].second]);
    }

    return sum;
}

int main(){
    optimize;

    int x, y, h, v;
    cin >> x >> y >> h >> v;

    vector<pii> a(h);
    vector<pii> b(v);

    for(int i = 0; i < h; i++)
        cin >> a[i].first >> a[i].second;

    for(int i = 0; i < v; i++)
        cin >> b[i].first >> b[i].second;

    cout << (h + 1LL) * (v + 1LL) + solve(a) + solve(b) << "\n";
    
    return 0;   
}
