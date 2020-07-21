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

struct Query{
    int t, i;
    ll v;
    Query(int _t = 0, int _i = 0, ll _v = 0) : t(_t), i(_i), v(_v){}
};

const int root = 450;
int sz = 0;
Query buffer[root];

int n, m;
ll val[MAXN];
ll frontCont[MAXN];
ll backCont[MAXN];
ll frontLazy[MAXN];
ll backLazy[MAXN];

void flushBuffer(){
    for(int i = 0; i < root; i++){
        int t = buffer[i].t, pos = buffer[i].i;
        ll v = buffer[i].v;
        if(t == 1){
            frontCont[pos]++;
            frontLazy[pos] += v;
            if(pos + v < n)
                frontCont[pos + v]--;
        }
        else{
            backCont[pos]++;
            backLazy[pos] += v;
            if(pos - v >= 0)
                backCont[pos - v]--;
        }
    }

    sz = 0;

    for(int i = 0; i < n; i++){
        val[i] += frontLazy[i];
        if(i < n - 1){
            frontLazy[i + 1] += frontLazy[i] - frontCont[i];
            frontCont[i + 1] += frontCont[i];
        }
        frontLazy[i] = 0;
        frontCont[i] = 0;
    }

    for(int i = n - 1; i >= 0; i--){
        val[i] += backLazy[i];
        if(i > 0){
            backLazy[i - 1] += backLazy[i] - backCont[i];
            backCont[i - 1] += backCont[i];
        }
        backLazy[i] = 0;
        backCont[i] = 0;
    }
}

void addQuery(Query q){
    if(sz == root)
        flushBuffer();
    buffer[sz++] = q;
}

ll getValue(int x){
    ll ans = val[x];
    for(int i = 0; i < sz; i++){
        int t = buffer[i].t, pos = buffer[i].i;
        ll v = buffer[i].v;
        if(t == 1 && x >= pos)
            ans += max(0LL, v - (x - pos));
        else if(t == 2 && x <= pos)
            ans += max(0LL, v - (pos - x));
    }
    return ans;
}

int main(){
    optimize;
    
    cin >> n >> m;

    while(m--){
        int t, i;
        cin >> t >> i;
        if(t == 3){
            cout << getValue(i - 1) << "\n";
        }
        else{
            ll v;
            cin >> v;
            addQuery(Query(t, i - 1, v));
        }
    }

    return 0;   
}
