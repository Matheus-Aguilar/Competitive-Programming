#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 998244353
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 1100

using namespace std;

//DP[i][j][m] = numero de formas de ter j componentes com i colunas terminando
//com o padrao m

//Definicao do padrao m
// m = 0, as celulas da ultima coluna tem a mesma cor
// m = 1, as celulas da ultima coluna tem cores diferentes

ll dp[MAXN][2 * MAXN][2];

int main(){
    optimize;

    int n, k;
    cin >> n >> k;

    ms(dp, 0);

    for(int i = 1; i <= n; i++){
        dp[i][1][0] = 2;
        dp[i][2][1] = 4 * i - 2;
    }

    for(int i = 2; i <= n; i++){
        dp[i][2][0] = ((dp[i - 1][1][0] + dp[i - 1][2][0]) mod + (2 * dp[i - 1][2][1]) mod) mod;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 3; j <= 2 * i; j++){
            dp[i][j][0] = ((dp[i - 1][j - 1][0] + dp[i - 1][j][0]) mod + (2 * dp[i - 1][j][1]) mod) mod; 
            dp[i][j][1] = ((2 * dp[i - 1][j - 1][0]) mod + (dp[i - 1][j - 2][1] + dp[i - 1][j][1]) mod) mod;
        }
    }

    cout << (dp[n][k][0] + dp[n][k][1]) mod << "\n";

    return 0;   
}
