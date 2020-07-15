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
#define MAXN 1024

using namespace std;

long double dp[MAXN][MAXN][2];

int main(){
    optimize;

    int w, b;
    cin >> w >> b;

    for(int i = 1; i <= w; i++){
        dp[i][0][0] = 1.0L;
        dp[i][0][1] = 0.0L;
    }

    for(int i = 0; i <= b; i++)
        dp[0][i][0] = dp[0][i][1] = 0.0L;

    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= b; j++){
            long double t = i + j;
            dp[i][j][0] = i/t + (j/t) * dp[i][j - 1][1];
            if(j > 1)
                dp[i][j][1] = (j/t) * ((i/(t - 1)) * dp[i - 1][j - 1][0]  + ((j - 1)/(t - 1)) * dp[i][j - 2][0]);
            else
                dp[i][j][1] = (1.0L/t) * dp[i - 1][0][0];
        }
    }

    cout << fixed << setprecision(9) << dp[w][b][0] << "\n";
    
    return 0;   
}
