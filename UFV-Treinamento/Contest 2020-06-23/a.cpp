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
#define MAXN 5100

using namespace std;

int n, m;
int dp[MAXN][MAXN];
int a[MAXN];

int solve(int i, int j){
    if(i == n)
        return 0;
    if(dp[i][j] == -1){
        dp[i][j] = 1 + solve(i + 1, j);
        if(j <= a[i])
            dp[i][j] = min(dp[i][j], solve(i + 1, a[i]));
    }
    return dp[i][j];
}

int main(){
    optimize;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        long double aux;
        cin >> a[i] >> aux;
    }

    ms(dp, -1);
    cout << solve(0, 0) << "\n"; 
    
    return 0;   
}
