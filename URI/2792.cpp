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
#define MAXN 500100

using namespace std;

int n, fenwick[MAXN];

int query(int x){
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += fenwick[x];
    return sum;
}

int update(int x, int v){
    for(; x <= n; x += x&-x)
        fenwick[x] += v;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 1; i <= n; i++)
        update(i, 1);

    for(int i = 1; i <= n; i++){
        int pos;
        cin >> pos;
        cout << query(pos) << (i != n ? ' ' : '\n');
        update(pos, -1);
    }

    return 0;   
}
