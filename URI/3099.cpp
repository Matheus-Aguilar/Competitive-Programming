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

using namespace std;

int digit, sz, limits[14];
ll rem[14], pot[14], dp[14][2];

ll solve(int i, int j){
    if(i < 0)
        return 0LL;
    if(dp[i][j] == -1){
        if(j == 1)
            dp[i][j] = 10 * solve(i - 1, j) + pot[i];
        else if(limits[i] > digit)
            dp[i][j] = limits[i] * solve(i - 1, 1) + solve(i - 1, 0) + pot[i];
        else if(limits[i] == digit)
            dp[i][j] = limits[i] * solve(i - 1, 1) + solve(i - 1, 0) + rem[i] + 1;
        else
            dp[i][j] = limits[i] * solve(i - 1, 1) + solve(i - 1, 0);
    }
    return dp[i][j];
}

int main(){
    optimize;
    
    ll n, n1 = 0, n7 = 0, aux;
    cin >> n;

    aux = n;

    for(sz = 0; aux; sz++){
        limits[sz] = aux % 10;
        pot[sz] = (sz == 0 ? 1 : pot[sz - 1] * 10);
        rem[sz] = n % pot[sz];
        aux /= 10;
    }

    ms(dp, -1);
    digit = 1;
    n1 = solve(sz - 1, 0);

    ms(dp, -1);
    digit = 7;
    n7 = solve(sz - 1, 0);

    cout << n1 + n7 << "\n";

    return 0;   
}
