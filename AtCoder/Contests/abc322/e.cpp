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
#define MAXN 110

using namespace std;

int n, k, p, a[MAXN][5];
ll c[MAXN], dp[MAXN][6][6][6][6][6];

ll solve(int i, int p1, int p2, int p3, int p4, int p5){
    if(i == n)
        return ((p1 >= p && p2 >= p && p3 >= p && p4 >= p && p5 >= p) ? 0 : INFLL);
    if(dp[i][p1][p2][p3][p4][p5] == -1)
        dp[i][p1][p2][p3][p4][p5] = min(solve(i + 1, p1, p2, p3, p4, p5), solve(i + 1, min(p1 + a[i][0], p), min(p2 + a[i][1], p), min(p3 + a[i][2], p), min(p4 + a[i][3], p), min(p5 + a[i][4], p)) + c[i]);
    return dp[i][p1][p2][p3][p4][p5];
}

int main(){
    optimize;

    ms(dp, -1);

    cin >> n >> k >> p;

    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < k; j++)
            cin >> a[i][j];
    }

    int initial[5] = {0};

    for(int i = k; i < 5; i++)
        initial[i] = p;

    ll val = solve(0, initial[0], initial[1], initial[2], initial[3], initial[4]);

    if(val < INFLL)
        cout << val << "\n";
    else
        cout << -1 << "\n";
    
    return 0;   
}
