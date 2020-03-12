#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAXN 1010

using namespace std;

long double dp[MAXN][MAXN];

int main()
{
    int N, M;

    cin >> N >> M;

    for(int i = 0; i <= N; i++)
        dp[i][0] = 1;
    for(int i = 0; i <= M; i++)
        dp[0][i] = 0;
    dp[1][1] = 0.5;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(i == 1 && j == 1) continue;
            long double total = i + j;
            long double A = (j/total) * ((j - 1)/(total - 1)) * ((j - 2)/(total - 2));
            long double B = (j/total) * ((j - 1)/(total - 1)) * (i/(total - 2));
            dp[i][j] = i/total + A * (j >= 3 ? dp[i][j - 3] : 0) + B * (j >= 2 && i >= 1 ? dp[i - 1][j - 2] : 0);
        }
    }

    cout << setprecision(9) << fixed;
    
    cout << dp[N][M] << endl;
}