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

int n, k, q, a[MAXN], bit[MAXN];

void update(int x, int v){
    for(; x <= MAXN; x += x&-x)
        bit[x] += v;
}

int query(int x){
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += bit[x];
    return sum;
}

void build(){
    for(int i = 1; i < MAXN; i++)
        update(i, a[i]);
}

int main(){
    optimize;
    
    cin >> n >> k >> q;

    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        a[l] += 1;
        a[r + 1] += -1;
    }

    for(int i = 1; i < MAXN; i++)
        a[i] += a[i - 1];
    for(int i = 1; i < MAXN; i++)
        a[i] = (a[i] >= k);
    
    build();
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(r) - query(l - 1) << "\n";
    }

    return 0;   
}
