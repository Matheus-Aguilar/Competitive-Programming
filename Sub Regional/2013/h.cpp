#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

ll n, c1, c2;

void mult(ll a[2][2], ll b[2][2]){
    ll c[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            c[i][j] = 0;
            for(int k = 0; k < 2; k++){
                c[i][j] += (a[i][k] * b[k][j]) mod;
                c[i][j] = c[i][j] mod;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            a[i][j] = c[i][j];
        }
    }
}

ll fastExpo(ll x[2][2], ll n){

    ll m[2][2] = {{1, 0}, {0, 1}};
    while(n > 0){
        if(n & 1)
            mult(m, x);
        mult(x, x);
        n >>= 1;
    }

    return ((c1 * m[0][0]) mod + m[0][1]) mod;
}

ll solve(ll n){
    if(n == 0) 
        return 1;
    if(n == 1) 
        return c1;
    ll m[2][2] = {{c1, c2}, {1, 0}};
    return fastExpo(m, n - 1);
}

int main(){
    optimize;

    while(cin >> n >> c1 >> c2){
        c1 = c1 mod;
        c2 = c2 mod;
        cout << setw(6) << setfill('0') << solve(n/5) << "\n";
    }
    return 0;   
}
