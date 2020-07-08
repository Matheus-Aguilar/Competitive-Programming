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
#define MAXN 200010
#define MAXA 1000100

using namespace std;

const int block = 450;

int n, t;
ll sum = 0, a[MAXN], cont[MAXA], ans[MAXN];

struct Query{
    int l, r, i;
    bool operator<(const Query &other) const{
        if(l/block != other.l/block)
            return l/block < other.l/block;
        return (l/block & 1) ? (r < other.r) : (r > other.r);
    }
};

Query q[MAXN];

void add(int x){
    sum += a[x] * (2 * cont[a[x]] + 1);
    cont[a[x]]++;
}

void remove(int x){
    sum -= a[x] * (2 * cont[a[x]] - 1);
    cont[a[x]]--;
}

ll getAns(){
    return sum;
}

void mo(){
    sort(q, q + t);

    int l = 0, r = -1;
    for(int i = 0; i < t; i++){
        while(l > q[i].l){
            l--;
            add(l);
        }
        while(r < q[i].r){
            r++;
            add(r);
        }
        while(l < q[i].l){
            remove(l);
            l++;
        }
        while(r > q[i].r){
            remove(r);
            r--;
        }
        ans[q[i].i] = getAns();
    }
}

int main(){
    optimize;

    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < t; i++){
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
        q[i].l--, q[i].r--;
    }

    mo();
    for(int i = 0; i < t; i++)
        cout << ans[i] << "\n";

    return 0;   
}
