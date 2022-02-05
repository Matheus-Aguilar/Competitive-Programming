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
#define MAXN 550

using namespace std;

int r, c, s[MAXN][MAXN], dp[MAXN][MAXN], ok[MAXN][MAXN];

int solve(int i, int j, int k){
    if(i == 0 && j == 0)
        return k;
    if(!ok[i][j]){
        dp[i][j] = -INF;

        if(i > 0)
            dp[i][j] = max(dp[i][j], s[i][j] + solve(i - 1, j, k));
        if(j > 0)
            dp[i][j] = max(dp[i][j], s[i][j] + solve(i, j - 1, k));
        if(dp[i][j] <= 0)
            dp[i][j] = -INF;

        ok[i][j] = true;
    }
    return dp[i][j];
}

bool check(int x){
    ms(ok, false);
    return solve(r - 1, c - 1, x) != -INF;
}

int binSearch(int l, int r){
    while(l < r){
        int m = l + (r - l) / 2;
        if(check(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        cin >> r >> c;

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> s[i][j];
        
        cout << binSearch(1, INF) << "\n";
    }
    
    return 0;   
}
