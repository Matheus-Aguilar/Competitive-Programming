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
#define MAXN 110
#define MAXS 10010

using namespace std;

int dp[MAXN][MAXS];
int n, k, c[MAXN], sum;

int solve(int i, int j){
    if(n == i)
        return max(j, sum - j);
    if(dp[i][j] == -1)
        dp[i][j] = min(solve(i + 1, j + c[i]), solve(i + 1, j));
    return dp[i][j];
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        ms(dp, -1);
        
        cin >> n >> k;
        
        sum = 0;

        for(int i = 0; i < n; i++){
            cin >> c[i];
            sum += c[i];
        }
        
        cout << (solve(0, 0) <= k ? "YES" : "NO") << "\n";
    }

    return 0;   
}
