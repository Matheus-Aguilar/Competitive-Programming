#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

int dp[55][550][550], n, a, b, c, arr[55], sum = 0;

int solve(int i, int ka, int kb){
    
    if(i == n){
        int kc = sum - ka - kb;
        int ta = (ka + a - 1) / a;
        int tb = (kb + b - 1) / b;
        int tc = (kc + c - 1) / c;
        return max(max(ta, tb), tc);
    }

    if(dp[i][ka][kb] == -1){
        dp[i][ka][kb] = INF;
        dp[i][ka][kb] = min(dp[i][ka][kb], solve(i + 1, ka + arr[i], kb));
        dp[i][ka][kb] = min(dp[i][ka][kb], solve(i + 1, ka, kb + arr[i]));
        dp[i][ka][kb] = min(dp[i][ka][kb], solve(i + 1, ka, kb));
    }

    return dp[i][ka][kb];
}

int main(){

    optimize;

    memset(dp, -1, sizeof(dp));

    cin >> n >> a >> b >> c;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    cout << solve(0, 0, 0) << "\n";

    return 0;
}