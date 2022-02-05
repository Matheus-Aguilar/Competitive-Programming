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
#define MAXN 510

using namespace std;

int N, L, K, d[MAXN], a[MAXN], dp[MAXN][MAXN];

int solve(int i, int k){
    if(i == N)
        return 0;
    if(dp[i][k] == -1){
        dp[i][k] = INF;

        for(int j = 0; j <= k && i + j + 1 <= N; j++){
            dp[i][k] = min(dp[i][k], a[i] * (d[i + j + 1] - d[i]) + solve(i + j + 1, k - j));
        }
    }
    return dp[i][k];
}

int main(){
    optimize;

    ms(dp, -1);
    
    cin >> N >> L >> K;

    for(int i = 0; i < N; i++)
        cin >> d[i];
    
    d[N] = L;

    for(int i = 0; i < N; i++)
        cin >> a[i];

    cout << solve(0, K) << "\n";

    return 0;   
}
