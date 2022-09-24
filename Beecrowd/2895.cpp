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

    vector<int> dp(5097, INF);
    vector<int> m(24);
    
    for(int i = 0; i < 12; i++){
        m[i] = (1 << i);
        m[12 + i] = -m[i];
    }

    dp[0] = 0;
    for(int i = 0; i < 24; i++){
        for(int j = 5096; j >= 0; j--){
            if(dp[j] != INF && 0 <= j + m[i] && j + m[i] <= 5096)
                dp[j + m[i]] = min(dp[j + m[i]], dp[j] + 1);
        }
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;   
}
