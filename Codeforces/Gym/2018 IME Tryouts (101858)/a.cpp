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
#define MAXN 10000010

using namespace std;

ll dp[MAXN];

int main(){
    optimize;

    ll sum = 1;
    dp[0] = 1;

    for(int i = 2; i < MAXN; i += 2){
        dp[i] = (2 * sum) mod;
        dp[i] = (dp[i] + dp[i - 2]) mod;
        sum = (sum + dp[i]) mod;
    }

    int n;
    cin >> n;
    cout << dp[n] << "\n";
    
    return 0;   
}
