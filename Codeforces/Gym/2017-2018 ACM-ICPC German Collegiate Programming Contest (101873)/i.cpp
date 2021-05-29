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
#define MAXN 310000

using namespace std;

int n, m, dp[MAXN], x[MAXN];

int solve(int i){
    if(i >= n)
        return 0;
    if(dp[i] == -1)
        dp[i] = max(solve(i + 1), solve(i + m) + x[i]);
    return dp[i];
}

int main(){
    optimize;
    
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> x[i];

    ms(dp, -1);

    cout << solve(m) << "\n";

    return 0;   
}
