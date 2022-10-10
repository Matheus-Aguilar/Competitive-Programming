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

ll calc(string &s, int n){
    
    vector<ll> dp(n + 1);

    dp[n] = 1;
    dp[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--){
        if(s[i] == 'A')
            dp[i] = dp[i + 1] + dp[i + 2];
        else
            dp[i] = dp[i + 1];
    }

    return dp[0];
}

int main(){
    optimize;

    string s;
    cin >> s;

    cout << calc(s, s.size()) << "\n";

    return 0;   
}
