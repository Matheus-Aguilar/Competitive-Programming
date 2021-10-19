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

int bit[MAXN];

void update(int x, int n, int v){
    while(x <= n){
        bit[x] += v;
        x += -x & x;
    }
}

int query(int x){
    int sum = 0;
    while(x > 0){
        sum += bit[x];
        x -= -x & x;
    }
    return sum;
}

int query(int a, int b){
    return query(b) - query(a - 1);
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        ms(dp, 0);

        int n, m;
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            update(i, n, 1);
        }

        for(int i = 0; i < m; i++){
            
        }
    }
    
    return 0;   
}
