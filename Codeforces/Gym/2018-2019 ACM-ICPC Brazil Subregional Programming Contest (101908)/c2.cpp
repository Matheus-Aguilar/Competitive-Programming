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

ll fenwick[MAXN];

void update(int x, int n, int v){
    for(; x <= n; x += -x&x)
        fenwick[x] += v;
}

void build(int n){
    memset(fenwick, 0, sizeof(ll) * (n + 1));
    for(int i = 1; i <= n; i++)
        update(i, n, 1);
}

ll query(int x){
    ll sum = 0;
    for(; x > 0; x -= -x&x)
        sum += fenwick[x];
    return sum;
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
        end[out[i].second] = i + 1;

    build(n);

    for(int i = 0; i < n; i++){
        update(end[in[i].second], n, -1);
        sum += query(end[in[i].second]);
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
