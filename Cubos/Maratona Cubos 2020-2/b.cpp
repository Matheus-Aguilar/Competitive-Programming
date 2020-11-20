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

        vector<int> dp(k + 1, 0);
        vector<vector<int>> q(k + 1, vector<int>(n));

        for(int i = 0; i < n; i++)
            q[0][i] = c[i];

        for(int i = 1; i <= k; i++){
            
            int best = -1;
            dp[i] = dp[i - 1];
            q[i] = q[i - 1];
            
            for(int j = 0; j < n; j++){
                if(i - a[j] >= 0 && q[i - a[j]][j] > 0 && dp[i - a[j]] + b[j] > dp[i]){
                    dp[i] = dp[i - a[j]] + b[j];
                    best = j;
                }
            }

            if(best != -1){
                q[i] = q[i - a[best]];
                q[i][best]--;
            }
        }

        cout << dp.back() << "\n";
    }
    
    return 0;   
}
