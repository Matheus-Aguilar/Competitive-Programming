#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % M
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 410

using namespace std;

int n;
ll M, ans = 0, dp[MAXN][MAXN][2], fat[MAXN];

void precalc(){

    fat[0] = 1LL;

    for(int i = 1; i < MAXN; i++)
        fat[i] = (fat[i - 1] * i mod) mod;
}

ll solve(int i, int j, int k){
    if(i == n - 1)
        return j == 1;
    if(j == 0)
        return 0;
    if(dp[i][j][k] == -1){
        if(k == 1)
            dp[i][j][k] = solve(i + 1, j - 1, 0);
        else
            dp[i][j][k] = (solve(i + 1, j - 1, 0) + solve(i + 1, j, 1)) mod;
    }
    return dp[i][j][k];
}

int main(){
    optimize;

    cin >> n >> M;

    precalc();
    ms(dp, -1);

    for(int i = 1; i <= n; i++){
        ll cont = solve(0, i, 1);
        ll perm = (cont * fat[i]) mod;
        ans = (ans + perm) mod;
    }

    cout << ans << "\n";

    return 0;   
}
