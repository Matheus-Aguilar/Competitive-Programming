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
#define MAXN 200100

using namespace std;

int n, a[MAXN], idx[MAXN];

bool cmp(int x, int y){
    return a[x] < a[y];
}

bool canPair(int x, int y){
    return x / 2 != y / 2;
}

ll dp[MAXN][2][2][2];

ll solve(int i, int j1, int j2, int j3){

    if(i == n){
        return ((j1 && j2 && j3) ? 0 : INFLL);
    }
    
    if(dp[i][j1][j2][j3] == -1){
        
        dp[i][j1][j2][j3] = INFLL;

        if(j3){
            dp[i][j1][j2][j3] = min(dp[i][j1][j2][j3], solve(i + 1, 0, j1, j2));
        }

        if(!j1 && j3 && canPair(idx[i], idx[i - 1])){
            dp[i][j1][j2][j3] = min(dp[i][j1][j2][j3], solve(i + 1, 1, 1, j2) + abs(a[idx[i]] - a[idx[i - 1]]));
        }
        
        if(!j2 && j3 && canPair(idx[i], idx[i - 2])){
            dp[i][j1][j2][j3] = min(dp[i][j1][j2][j3], solve(i + 1, 1, j1, 1) + abs(a[idx[i]] - a[idx[i - 2]]));
        }

        if(!j3 && canPair(idx[i], idx[i - 3])){
            dp[i][j1][j2][j3] = min(dp[i][j1][j2][j3], solve(i + 1, 1, j1, j2) + abs(a[idx[i]] - a[idx[i - 3]]));
        }
    }

    return dp[i][j1][j2][j3];
}

int main(){
    optimize;

    ms(dp, -1);
    
    cin >> n;
    n <<= 1;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    iota(idx, idx + n, 0);
    sort(idx, idx + n, cmp);

    cout << solve(0, 1, 1, 1) << "\n";

    return 0;   
}
