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

const int sz = 500;

int n, m, c;

ll a[MAXN], b[MAXN], d[MAXN];

void build() {

    c = (n + sz - 1) / sz;

    for(int i = 0; i < c; i++){
        b[i] = 0;
        d[i] = 0;
    }

    for(int i = 0; i < n; i++){
        b[i / sz] += a[i];
        d[i / sz] += (a[i] != 1);
    }
}

void updatePos(int x){
    if(a[x] != 1){
        int bx = x / sz;
        
        ll upd = sqrt(a[x]);

        b[bx] += (upd - a[x]);
        d[bx] -= (upd == 1);

        a[x] = upd;
    }
}

void updateBucket(int x){
    if(d[x] != 0){
        for(int i = sz * x; i < (x + 1) * sz && i < n; i++)
            updatePos(i);
    }
}

void update(int l, int r){
    int bl = l / sz, br = r / sz;
    int nxt = min((bl + 1) * sz, n), last = min(br * sz, n - 1);

    if(bl != br) {
        for(int i = bl + 1; i < br; i++)
            updateBucket(i);
        for(int i = l; i < nxt; i++)
            updatePos(i);
        for(int i = last; i <= r; i++)
            updatePos(i);
    }
    else {
        for(int i = l; i <= r; i++)
            updatePos(i);
    }
}

ll query(int l, int r){
    int bl = l / sz, br = r / sz;
    int nxt = min((bl + 1) * sz, n), last = min(br * sz, n - 1);

    ll sum = 0;

    if(bl != br){
        for(int i = bl + 1; i < br; i++)
            sum += b[i];
        for(int i = l; i < nxt; i++)
            sum += a[i];
        for(int i = last; i <= r; i++)
            sum += a[i];
    }
    else {
        for(int i = l; i <= r; i++)
            sum += a[i];
    }

    return sum;
}

int main(){
    optimize;

    int t = 1;

    while(cin >> n) {

        cout << "Case #" << t << ":\n";

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        build();

        cin >> m;

        while(m--){
            int q, x, y;
            cin >> q >> x >> y;

            if(x > y)
                swap(x, y);

            if(q == 0){
                update(x - 1, y - 1);
            }
            else{
                cout << query(x - 1, y - 1) << "\n";
            }
        }

        cout << "\n";
        t++;
    }
    
    return 0;   
}
