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
#define MAXN 100100

using namespace std;

int n, ans = 0, dp[MAXN];

int main(){
    optimize;
    
    string s;
    cin >> s;

    n = s.size();
    ms(dp, -1);

    for(int i = 1; i < n; i++){
        int g = __gcd(i, n);

        if(dp[g] == -1){
            
            for(int j = 0; j < g; j++){
                
                dp[g] = 1;
                
                for(int k = j; k < n; k += g){
                    if(s[k] == 'P'){
                        dp[g] = 0;
                        break;
                    }
                }

                if(dp[g] == 1)
                    break;
            }
        }

        ans += dp[g];
    }

    cout << ans << "\n";

    return 0;   
}
