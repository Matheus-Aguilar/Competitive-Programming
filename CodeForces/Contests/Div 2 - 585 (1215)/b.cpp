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

int main(){
    optimize;

    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> dp(n, vector<int>(2));

    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = (a[i] > 0 ? 1 : -1);
    }

    dp[0][0] = (a[0] > 0);
    dp[0][1] = (a[0] < 0);
    for(int i = 1; i < n; i++){
        if(a[i] > 0){
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1];
        }
        else{
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1;
        }
    }

    ll pos = 0, neg = 0;
    for(int i = 0; i < n; i++){
        pos += dp[i][0];
        neg += dp[i][1];
    }

    cout << neg << " " << pos << "\n";
    
    return 0;   
}
