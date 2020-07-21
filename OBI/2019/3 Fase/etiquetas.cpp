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
#define MAXN 10001

using namespace std;

int n, c, k;
int dp[MAXN][MAXN];
int a[MAXN];

int solve(int i, int j){
    if(i + j * c - 1 > n)
        return INF + 1;
    if(j == 0)
        return 0;
    if(dp[i][j] == INF)
        dp[i][j] = min(solve(i + 1, j), a[i + c - 1] - a[i - 1] + solve(i + c, j - 1));
    return dp[i][j];
}

int main(){
    optimize;

    ms(dp, INF);
    cin >> n >> k >> c;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    cout << a[n] - solve(1, k) << "\n";
    
    return 0;   
}
