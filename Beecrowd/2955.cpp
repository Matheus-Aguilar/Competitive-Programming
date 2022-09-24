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

ll possibilities(int x){
    vector<ll> dp(x + 1, 0LL);

    dp[0] = 1LL;

    for(int i = 0; i < x; i++){
        if(i != x - 1){
            for(int j = 3; i + j < x + 3; j += 3){
                dp[min(i + j, x)] = (dp[min(i + j, x)] + dp[i]) mod;
            }
        }
        dp[i + 1] = (dp[i + 1] + dp[i]) mod;
    }

    return dp[x];
}

int minRounds(int x){
    vector<int> dp(x + 1, INF);

    dp[0] = 0;

    for(int i = 0; i < x; i++){
        if(i != x - 1){
            for(int j = 3; i + j <= x; j += 3){
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }

    return dp[x];
}

int main(){
    optimize;

    int x;
    cin >> x;

    cout << possibilities(x) << " " << minRounds(x) << "\n";
    
    return 0;   
}
