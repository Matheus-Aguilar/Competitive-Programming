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
#define MAXN 150

using namespace std;

int n, m, a[MAXN], pts[MAXN], ans[MAXN], dp[MAXN][3000];
string s[MAXN];

int solve(int i, int j, int k){
    if(j <= 0)
        return 0;
    if(i == m)
        return INF;
    if(dp[i][j] == -1){
        dp[i][j] = solve(i + 1, j, k);
        if(s[k][i] == 'x')
            dp[i][j] = min(dp[i][j], solve(i + 1, j - a[i] / 100, k) + 1);
    }
    return dp[i][j];
}

int main(){
    optimize;

    cin >> n >> m;

    for(int i = 0; i < m; i++)
        cin >> a[i];
    
    int high = 0;

    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'o'){
                pts[i] += a[j];
            }
        }
        pts[i] += i + 1;
        high = max(high, pts[i]);
    }

    for(int i = 0; i < n; i++){

        if(high == pts[i]){
            ans[i] = 0;
            continue;
        }
        
        int diff = high - pts[i] + 1;
        int needed = (diff + 99) / 100;
        
        ms(dp, -1);
        ans[i] = solve(0, needed, i);
    }
    
    for(int i = 0; i < n; i++)
        cout << ans[i] << "\n";

    return 0;   
}
