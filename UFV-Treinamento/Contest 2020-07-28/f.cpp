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
#define MAXN 1001
#define MAXS 10001

using namespace std;

int n;
ll ans = 0, a[MAXN], dp[MAXN][MAXS][2];

ll solve(int i, int j, int k){
    if(i == n)
        return (j == 0);
    if(dp[i][j][k] == -1){
        int jplus = (k ? -j : j) + a[i];
        int jminus = (k ? -j : j) - a[i];
        int kplus = (jplus < 0);
        int kminus = (jminus < 0);
        dp[i][j][k] = ((j == 0) + ((solve(i + 1, abs(jplus), kplus) + solve(i + 1, abs(jminus), kminus)) mod)) mod;
    }
    return dp[i][j][k];
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    ms(dp, -1);

    for(int i = 0; i < n; i++)
        ans = (ans + ((2 * solve(i + 1, a[i], 0) mod))) mod;

    cout << ans << "\n";
    
    return 0;   
}
