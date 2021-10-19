#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 998244353
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 1010

using namespace std;

int n, k, nxt[MAXN], a[MAXN];
ll dp[MAXN][MAXN];

ll solve(int i, int j){
    if(i == n)
        return (j == 0);
    if(j == 0)
        return 1;
    if(dp[i][j] == -1)
        dp[i][j] = (solve(nxt[i], j - 1) + solve(i + 1, j)) mod;
    return dp[i][j];
}

int main(){
    optimize;

    ms(dp, -1);
    
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);

    for(int i = 0; i < n; i++)
        nxt[i] = upper_bound(a, a + n, a[i]) - a;

    cout << solve(0, k) << "\n";

    return 0;   
}
