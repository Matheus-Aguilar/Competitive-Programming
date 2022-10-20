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
#define MAXN 1100

using namespace std;

int dp[MAXN][MAXN];

int main(){
    optimize;

    string a, b;
    cin >> a >> b;
    
    for(int i = (int) a.size() - 1; i >= 0; i--){
        for(int j = (int) b.size() - 1; j >= 0; j--){
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    cout << dp[0][0] << "\n";

    return 0;   
}
