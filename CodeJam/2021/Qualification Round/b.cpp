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

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        int x, y;
        string s;

        cin >> x >> y >> s;

        vector<vector<ll>> dp(s.size(), vector<ll>(2));
        const char c[2] = {'C', 'J'};

        for(int i = 0; i < 2; i++)
            dp[s.size() - 1][i] = 0;

        if(s.back() != '?')
            dp[s.size() - 1][s.back() == 'C'] = INFLL;

        for(int i = s.size() - 2; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                if(s[i] != '?' && s[i] != c[j])
                    dp[i][j] = INFLL;
                else
                    dp[i][j] = min(dp[i + 1][j], dp[i + 1][j ^ 1] + (j ? y : x));
            }
        }

        cout << "Case #" << t << ": " << min(dp[0][0], dp[0][1]) << "\n";
    }
    
    return 0;   
}
