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

int n, h, l, r;
int isGood(int i, int j){
    return l <= (i + j) % h && (i + j) % h <= r;
}

int main(){
    optimize;

    cin >> n >> h >> l >> r;  
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<vector<int>> dp(n, vector<int>(h));
    for(int i = 0; i < h; i++)
        dp[n - 1][i] = max(isGood(i, a[n - 1]), isGood(i, a[n - 1] - 1));
    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j < h; j++){
            dp[i][j] = max(
                dp[i + 1][(j + a[i]) % h] + isGood(j, a[i]),
                dp[i + 1][(j + a[i] - 1) % h] + isGood(j, a[i] - 1)
            ); 
        }
    }

    cout << dp[0][0] << "\n";

    return 0;   
}
