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
#define fi first
#define se second

using namespace std;

bool cmp(const pii &a, const pii &b){
    if(a.se >= a.fi){
        if(b.fi > b.se)
            return true;
        else{
            if(a.fi != b.fi)
                return a.fi < b.fi;
            return a.se > b.se;
        }
    }
    else{
        if(b.se >= b.fi)
            return false;
        else{
            if(a.se != b.se)
                return a.se > b.se;
            return a.fi < b.fi;
        }
    }
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, h, k;
        cin >> n >> h >> k;

        vector<pii> xy(n);
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

        for(int i = 0; i < n; i++)
            cin >> xy[i].fi >> xy[i].se;
        
        sort(all(xy), cmp);

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= k; j++){
                dp[i][j] = max(xy[i].fi + 1LL, xy[i].fi - xy[i].se + dp[i + 1][j]);
                if(j > 0)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            }
        }

        cout << (h >= dp[0][k] ? "Y" : "N") << "\n";
    }
    
    return 0;   
}
