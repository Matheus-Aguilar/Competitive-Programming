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

int main(){
    optimize;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(61));
    
    for(int i = 0; i <= 60; i++)
        dp[n][i] = 30 - i;
    for(int i = n - 1; i >= 0; i--)
        for(int j = 0; j <= 60; j++)
            dp[i][j] = max(30 - j, a[i] + dp[i + 1][max(j, a[i] + 30)]);

    int ans = 0;
    for(int i = 0; i < n - 1; i++)
        ans = max(ans, dp[i + 1][a[i] + 30] + a[i]);
    
    cout << ans << "\n";

    return 0;   
}
