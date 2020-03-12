#include<bits/stdc++.h>
#define INF 1 << 30

using namespace std;

int main(){
    
    string s;
    long long int k;
    cin >> s >> k;

    s += s;
    vector<long long int>dp(s.size(), -INF);

    dp[0] = s[0] == 'E' ? 0 : -INF;

    for(long long int i = 1; i < dp.size(); i++){
        if(s[i] == 'E')
            dp[i] = i;
        else
            dp[i] = dp[i - 1];
    }

    long long int res = 0;

    for(long long int i = s.size()/2; i < s.size(); i++)
        res += k - min(i - dp[i], k);

    cout << res << "\n";

    return 0;
}