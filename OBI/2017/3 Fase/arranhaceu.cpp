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

int n, q;
int bit[MAXN];
int a[MAXN];

int query(int x){
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += bit[x];
    return sum;
}

void update(int x, int v){
    for(; x <= n; x += x&-x)
        bit[x] += v;
}

int main(){
    optimize;

    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        update(i, a[i]);
    }

    while(q--){
        int t;
        cin >> t;

        if(t == 0){
            int k, p;
            cin >> k >> p;
            update(k, p - a[k]);
            a[k] = p;
        }
        else{
            int k;
            cin >> k;
            cout << query(k) << "\n";
        }
    }
    
    return 0;   
}
