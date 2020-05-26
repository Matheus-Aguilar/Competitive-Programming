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

int bit[MAXN];

void update(int x, int n, int add){
    for(; x <= n; x += x&-x)
        bit[x] += add;
}

int query(int x){
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += bit[x];
    return sum;
}

int binSearch(int l, int r, int k, int n){
    while(l < r){
        int m = l + (r - l)/2;
        if(query(m) >= k)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    optimize;

    int n, q, x;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> x;
        update(x, n, 1);
    }

    while(q--){
        cin >> x;
        if(x > 0)
            update(x, n, 1);
        else{
            int pos = binSearch(1, n + 1, -x, n);
            update(pos, n, -1);
        }
    }

    cout << binSearch(1, n + 1, 1, n) % (n + 1) << "\n";
    
    return 0;   
}
