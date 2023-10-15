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
#define MAXN 200200

using namespace std;

int n;
ll a, b, c, x[MAXN];

int mask[7] = {1, 2, 4, 3, 5, 6, 7};
ll l[7];

ll dp[MAXN][8];

ll solve(int i, int j){
    if(i == n)
        return (j == 7 ? 0 : INFLL);
    if(dp[i][j] == -1){
        
        dp[i][j] = solve(i + 1, j);
        
        for(int k = 0; k < 7; k++){
            if(!(mask[k] & j)){
                ll val = ((x[i] + l[k] - 1) / l[k]) * l[k];
                dp[i][j] = min(dp[i][j], solve(i + 1, (j | mask[k])) + val - x[i]);
            }
        }
    }
    return dp[i][j];
}

int main(){
    optimize;

    ms(dp, -1);
    
    cin >> n >> a >> b >> c;

    for(int i = 0; i < n; i++)
        cin >> x[i];

    l[0] = a;
    l[1] = b;
    l[2] = c;
    l[3] = (a * b) / __gcd(a, b);
    l[4] = (a * c) / __gcd(a, c);
    l[5] = (b * c) / __gcd(b, c);
    l[6] = (l[3] * c) / __gcd(l[3], c);

    cout << solve(0, 0) << "\n";

    return 0;   
}
