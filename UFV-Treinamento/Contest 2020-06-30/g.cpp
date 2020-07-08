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

int n;
ll dp[MAXN][(1 << 4)];
ll a[MAXN];
string s;

ll solve(int i, int j){
    if(i == n)
        return (j != (1 << 4) - 1 ? 0LL : INFLL);
    if(dp[i][j] == -1){
        if(s[i] == 'h')
            dp[i][j] = min(solve(i + 1, j | (1 << 3)), solve(i + 1, j) + a[i]);
        else if(s[i] == 'a'){
            if(j & (1 << 3))
                dp[i][j] = min(solve(i + 1, j | (1 << 2)), solve(i + 1, j) + a[i]);
            else
                dp[i][j] = solve(i + 1, j);
        }
        else if(s[i] == 'r'){
            if(j & (1 << 2))
                dp[i][j] = min(solve(i + 1, j | (1 << 1)), solve(i + 1, j) + a[i]);
            else
                dp[i][j] = solve(i + 1, j);
        }
        else if(s[i] == 'd'){
            if(j & (1 << 1))
                dp[i][j] = min(solve(i + 1, j | (1 << 0)), solve(i + 1, j) + a[i]);
            else
                dp[i][j] = solve(i + 1, j);
        }
        else
            dp[i][j] = solve(i + 1, j);
    }
    return dp[i][j];
}

int main(){
    optimize;

    ms(dp, -1);

    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0, 0) << "\n";
    return 0;   
}
