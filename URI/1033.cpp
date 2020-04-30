#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll unsigned long long int
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef ll Matrix[2][2];

void multMod(Matrix a, Matrix b, ll base){
    Matrix c;
    ms(c, 0);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                c[i][j] += ((a[i][k] % base) * (b[k][j] % base)) % base;
                c[i][j] %= base;
            }
        }
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            a[i][j] = c[i][j];
}

void fastExpo(Matrix x, ll n, ll b){
    Matrix r;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            r[i][j] = (ll)(i == j);
    while(n > 0){
        if(n & 1)
            multMod(r, x, b);
        multMod(x, x, b);
        n >>= 1;
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            x[i][j] = r[i][j];
}

ll solve(ll n, ll b){
    Matrix m = {{1, 1}, {1, 0}};
    fastExpo(m, n - 1, b);
    ll ans = m[0][0] + m[0][1];
    ans = ((2 % b) * ans) % b;
    ans = (ans - 1 + b) % b; 
    return ans;
} 

int main(){
    optimize;

    int t = 1;
    ll n, b;
    while(cin >> n >> b){
        if(n == b && n == 0) break;
        cout << "Case " << t++ << ": ";
        if(n <= 1)
            cout << n << " " << b << " " << 1 << "\n";
        else
            cout << n << " " << b << " " << solve(n, b) << "\n";
    }
    return 0;   
}
