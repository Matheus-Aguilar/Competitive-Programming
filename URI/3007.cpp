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
        
        int n, f = INF;
        cin >> n;

        vector<int> q(n);
        for(int i = 0; i < n; i++)
            cin >> q[i];
    
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(__gcd(q[i], q[j]) == 1)
                    f = min(f, q[i] * q[j] - (q[i] + q[j]));
        
        if(f > 1000000)
            cout << -1 << "\n";
        else{
            vector<bool> dp(f + 1, false);
            dp[0] = true;

            for(int i = 0; i < f; i++){
                if(dp[i]){
                    for(int j = 0; j < n; j++){
                        if(i + q[j] <= f){
                            dp[i + q[j]] = true;
                        }
                    }
                }
            }

            for(int i = f; i >= 1; i--){
                if(!dp[i]){
                    cout << i << "\n";
                    break;
                }
            }
        }
    }
    
    return 0;   
}
