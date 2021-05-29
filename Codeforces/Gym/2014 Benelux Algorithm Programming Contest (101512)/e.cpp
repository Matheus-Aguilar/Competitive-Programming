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

struct R{
    int r1, r2, r3;
    bool operator<(const R &r){
        return r1 < r.r1;
    }
};

int n, bit[MAXN];
vector<R> r;

int query(int x){
    
    int ans = INF;
    
    for(; x > 0; x -= -x & x)
        ans = min(ans, bit[x]);

    return ans;
}

void update(int x, int v){
    for(; x <= n; x += -x & x)
        bit[x] = min(bit[x], v);
}

int main(){
    optimize;

    int T;
    cin >> T;

    while(T--){

        cin >> n;
        r.resize(n);

        for(int i = 0; i < n; i++)
            cin >> r[i].r1 >> r[i].r2 >> r[i].r3;
    
        sort(all(r));

        int cont = 0;
        ms(bit, INF);

        for(int i = 0; i < n; i++){
            if(query(r[i].r2) > r[i].r3){
                update(r[i].r2, r[i].r3);
                cont++;
            }
        }

        cout << cont << "\n";
    }
    
    return 0;   
}
