#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 5500
#define INF 0x3f3f3f3f

using namespace std;

int n, m, a[MAXN], dp[MAXN], cnt[MAXN];
bool valid[MAXN][MAXN], ok[MAXN];

int solve(int i){
    if(i > n)
        return 0;
    if(!ok[i]){
        
        ok[i] = true;
        dp[i] = -INF;
        
        for(int j = i; j <= n; j++){
            if(valid[i][j]){
                dp[i] = max(dp[i], solve(j + 1) + 1);
            }
        }
    }
    return dp[i];
}

int main() {
    optimize;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++){
        if(a[i] < m)
            cnt[i]++;
        cnt[i] += cnt[i - 1];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            
            int sz = j - i + 1;
            int mid = (sz + 1) / 2;
            
            if(cnt[j] - cnt[i - 1] < mid)
                valid[i][j] = true;
            
        }
    }

    int ans = max(0, solve(1));

    cout << ans << "\n";

    return 0;
}