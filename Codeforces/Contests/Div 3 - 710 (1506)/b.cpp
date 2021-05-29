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
#define MAXN 100

using namespace std;

int n, k, first, last;
int dp[MAXN][MAXN];

string s;

int solve(int i, int j){
    if(s[i] == '.')
        return solve(i + 1, j);
    if(i - j > k)
        return INF;
    if(i == last)
        return 1;
    if(dp[i][j] == -1)
        dp[i][j] = min(solve(i + 1, j), solve(i + 1, i) + 1);
    return dp[i][j];
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        cin >> n >> k >> s;

        ms(dp, -1);

        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                first = i;
                break;
            }
        }

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '*'){
                last = i;
                break;
            }
        }

        if(first == last)
            cout << 1 << "\n";
        else
            cout << 1 + solve(first + 1, first) << "\n";
    }
    
    return 0;   
}
