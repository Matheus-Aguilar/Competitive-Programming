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
#define MAXN 2010

using namespace std;

int n;
string s;

bool pal[MAXN][MAXN];
int dp[MAXN];

void preCalc(){
    for(int i = 0; i < n; i++)
        pal[i][i] = true;
    for(int i = 0; i < n - 1; i++)
        pal[i][i + 1] = (s[i] == s[i + 1]);
    for(int i = n - 3; i >= 0; i--){
        for(int j = i + 2; j < n; j++){
            if(s[i] != s[j])
                pal[i][j] = false;
            else
                pal[i][j] = pal[i + 1][j - 1];
        }
    }
}

int solve(int k){
    if(dp[k] == INF){
        if(pal[0][k])
            dp[k] = 1;
        else{
            for(int i = 1; i <= k; i++){
                if(pal[i][k]){
                    dp[k] = min(dp[k], 1 + solve(i - 1));
                }
            }
        }
    }
    return dp[k];
}

int main(){
    optimize;

    ms(dp, INF);

    cin >> n >> s;
    preCalc();
    cout << solve(n - 1) << "\n";

    return 0;   
}
