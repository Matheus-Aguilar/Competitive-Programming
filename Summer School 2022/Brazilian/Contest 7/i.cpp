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
int n, d[100];
ll dp[100][10][2];

ll solve(int i, int j, int k){
    if(i == n)
        return 1;
    if(j > 9)
        return 0;
    if(dp[i][j][k] == -1){

        dp[i][j][k] = 0;

        if(k == 0){
            dp[i][j][k] += solve(i + 1, d[i], 0);

            for(int x = j; x < d[i]; x++){
                dp[i][j][k] += solve(i + 1, x, 1);
            }
        }
        else {
            for(int x = j; x <= 9; x++){
                dp[i][j][k] += solve(i + 1, x, 1);
            }
        }
    }
    return dp[i][j][k];
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        cin >> s;

        n = s.size();

        bool ramp = true;

        for(int i = 1; i < n && ramp; i++){
            if(s[i - 1] > s[i]){
                ramp = false;
            }
        }

        if(!ramp){
            cout << -1 << "\n";
            continue;
        }

        ms(dp, -1);

        for(int i = 0; i < n; i++)
            d[i] = s[i] - '0';
        
        cout << solve(0, 0, 0) - 1 << "\n";
    }
    
    return 0;   
}
