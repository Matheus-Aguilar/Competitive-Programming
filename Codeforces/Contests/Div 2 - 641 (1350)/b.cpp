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
        int n;
        cin >> n;

        vector<int> s(n);
        vector<int> dp(n);

        for(int i = 0; i < n; i++)
            cin >> s[i];
        for(int i = n; i >= 1; i--){
            dp[i - 1] = 1;
            for(int j = 2 * i; j <= n; j += i)
                if(s[i - 1] < s[j - 1])
                    dp[i - 1] = max(dp[i - 1], 1 + dp[j - 1]);
        }
        cout << *max_element(all(dp)) << "\n";
    }

    return 0;   
}
