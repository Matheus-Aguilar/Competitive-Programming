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

    int n, k;

    cin >> k;

    string s1, s2;
    cin >> s1 >> s2;

    n = s1.size();

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -INF));

    dp[n][0] = 0;

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= k; j++){
            dp[i][j] = dp[i + 1][j] + (s1[i] != s2[i]);
            if(j > 0){
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + (s1[i] == s2[i]));
            }
        }
    }

    cout << dp[0][k] << "\n";
    
    return 0;   
}
