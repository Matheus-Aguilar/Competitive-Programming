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
#define MAXN 10010

using namespace std;

int m[7] = {1, 2, 2, 2, 2, 3, 3};
ll dp[MAXN];    

int main(){
    optimize;
    
    int n;
    cin >> n;

    dp[0] = 1;

    for(int i = 0; i <= n; i++){
        if(dp[i] > 0){
            for(int j = 0; j < 7; j++){
                if(i + m[j] <= n){
                    dp[i + m[j]] = (dp[i + m[j]] + dp[i]) mod;
                }
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;   
}
