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

string s;

int dp[100][100];

int solve(int i, int j){
    if(i == s.size())
        return 26 - j;
    if(j == 26)
        return 0;
    if(dp[i][j] == -1){
        if(j == (s[i] - 'a')){
            dp[i][j] = solve(i + 1, j + 1);
        }
        else{
            dp[i][j] = min(solve(i, j + 1) + 1, solve(i + 1, j));
        }
    }
    return dp[i][j];
}

int main(){
    optimize;

    ms(dp, -1);

    cin >> s;

    cout << solve(0, 0) << "\n";
    
    return 0;   
}
