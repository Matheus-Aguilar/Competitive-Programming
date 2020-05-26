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
 
void update(int node, int tl, int tr, int pos, int add){
    while(tl < tr){
        seg[node] += add;
        node <<= 1;
        int tm = tl + ((tr - tl) >> 1);
        if(pos <= tm){
            tr = tm;
        }
        else{
            tl = tm + 1;
            node ^= 1;
        }
    }
    seg[node] += add;
}
 
int query(int node, int tl, int tr, int k){
    while(tl < tr){
        int tm = tl + ((tr - tl) >> 1);
        node <<= 1;
        if(seg[node] >= k)
            tr = tm;
        else{
            tl = tm + 1;
            k -= seg[node];
            node ^= 1;
        }
    }
    return tl;
}
 
int main(){
    optimize;
 
    int n, q, x;
    cin >> n >> q;

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