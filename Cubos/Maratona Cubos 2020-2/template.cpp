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

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);

        for(int i = 0; i < n; i++)
            cin >> a[i] >> b[i] >> c[i];

        vector<int> v;
        vector<int> w;
        vector<vector<int>> dp(k + 1);
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < c[i] && b[i] * j <= k; j++){
                v.push_back(a[i]);
                w.push_back(b[i]);
            }
        }

        for(int i = 0; i <= k; i++){
            dp[i].resize((int)a.size() + 1);
            dp[i][0] = 0;
        }

        for(int i = 0; i < dp[0].size(); i++)
            dp[0][i] = 0;

        for(int i = 1; i <= k; i++){
            for(int j = 1; j < dp[i].size(); j++){
                dp[i][j] = dp[i][j - 1];
                if(i - w[j] >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - w[j]][j - 1] + v[j]);
            }
        }

        cout << dp.back().back() << "\n";
    }
    
    return 0;   
}
