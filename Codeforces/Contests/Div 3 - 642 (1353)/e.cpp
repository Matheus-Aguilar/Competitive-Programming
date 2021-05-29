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
#define MAXN 1000100

using namespace std;

int n, k;
string s;

int dp[MAXN];
int prefix[MAXN];

int solve(int pos){
    if(pos + k >= n)
        return (int)(s[pos] == '0') + prefix[n] - prefix[pos + 1];
    if(dp[pos] == -1){
        dp[pos] = (int)(s[pos] == '0') + min(
            prefix[pos + k] - prefix[pos + 1] + solve(pos + k),
            prefix[n] - prefix[pos + 1]
        );
    }
    return dp[pos];
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        cin >> n >> k >> s;       
        memset(dp, -1, sizeof(int) * (n + 1));
        
        vector<int> pos;
        prefix[0] = 0;

        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i];
            if(s[i] == '1'){
                prefix[i + 1]++;
                pos.push_back(i);
            }
        }

        int ans = INF;
        for(int i = 0; i < pos.size(); i++){
            ans = min(ans, i + solve(pos[i]));
        }
        if(pos.size() == 0) ans = 0;
        cout << ans << "\n";
    }
    
    return 0;   
}
