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
#define MAXN 250050

using namespace std;

int n, k;
ll a[MAXN], dp[MAXN][2][2][10][10];

int main(){
    optimize;
    
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = n; i >= 0; i--){
        for(int l1 = 0; l1 <= 1; l1++){
            for(int l2 = 0; l2 <= 1; l2++){
                for(int t1 = 0; t1 <= k; t1++){
                    for(int t2 = 0; t2 <= k; t2++){
                        
                        if(i == n){
                            dp[i][l1][l2][t1][t2] = ((l1 || l2) && (t1 == t2) ? 0 : INFLL);
                            continue;
                        }
                        
                        ll val = a[i] + dp[i + 1][l2][1][t1][t2];

                        if(t1 < k){
                            val = min(val, dp[i + 1][l2][1][t1 + 1][t2]);
                        }

                        if(l1 || l2){
                            val = min(val, dp[i + 1][l2][0][t1][t2]);

                            if(t2 < k){
                                val = min(val, a[i] + dp[i + 1][l2][0][t1][t2 + 1]);    
                            }
                        }

                        dp[i][l1][l2][t1][t2] = val;
                    }
                }
            }    
        }
    }

    cout << dp[0][1][0][0][0] << "\n";

    return 0;   
}
