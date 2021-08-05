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
#define MAXN 1000100

using namespace std;

int n, s, bit[MAXN];

void update(int x, int v){
    while(x < MAXN){
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

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        cout << n - i + query(s) << "\n";
        update(s + 1, 1);
    }
    
    return 0;   
}
