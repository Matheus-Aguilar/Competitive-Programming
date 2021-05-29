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
#define fi first
#define se second

using namespace std;

const int sz = 18;
const int MAXN = (1 << sz);

int dp[MAXN][2];
bool ok[MAXN][2];

pii adj[sz][2] = {
    {pii(1,2), pii(-1,-1)},
    {pii(0,2), pii(-1,-1)},
    {pii(0,1), pii(4,6)},

    {pii(4,5), pii(-1,-1)},
    {pii(3,5), pii(2,6)},
    {pii(3,4), pii(10,12)},
    
    {pii(7,8), pii(2,4)},
    {pii(6,8), pii(-1,-1)},
    {pii(6,7), pii(13,15)},
    
    {pii(10,11), pii(-1,-1)},
    {pii(9,11), pii(5,12)},
    {pii(9,10), pii(-1,-1)},
    
    {pii(13,14), pii(5,10)},
    {pii(12,14), pii(8,15)},
    {pii(12,13), pii(-1,-1)},
    
    {pii(16,17), pii(8,13)},
    {pii(15,17), pii(-1,-1)},
    {pii(15,16), pii(-1,-1)}
};

int solve(int i, int j){

    if(i == MAXN - 1)
        return 0;

    if(!ok[i][j]){
    
        if(j == 0){

            dp[i][j] = -INF;

            for(int k = 0; k < sz; k++){
                if((i & (1 << k)) == 0){

                    int cnt = 0, nxt = 1 - j;

                    if((i & (1 << adj[k][0].fi)) != 0 && (i & (1 << adj[k][0].se)) != 0){
                        nxt = j;
                        cnt++;
                    }
                    
                    if(adj[k][1].fi != -1 && (i & (1 << adj[k][1].fi)) != 0 && (i & (1 << adj[k][1].se)) != 0){
                        nxt = j;
                        cnt++;
                    }

                    dp[i][j] = max(dp[i][j], solve((i | (1 << k)), nxt) + cnt);
                }
            }
        }
        else{
            
            dp[i][j] = INF;

            for(int k = 0; k < sz; k++){
                if((i & (1 << k)) == 0){

                    int cnt = 0, nxt = 1 - j;

                    if((i & (1 << adj[k][0].fi)) != 0 && (i & (1 << adj[k][0].se)) != 0){
                        nxt = j;
                        cnt++;
                    }
                    
                    if(adj[k][1].fi != -1 && (i & (1 << adj[k][1].fi)) != 0 && (i & (1 << adj[k][1].se)) != 0){
                        nxt = j;
                        cnt++;
                    }

                    dp[i][j] = min(dp[i][j], solve((i | (1 << k)), nxt) - cnt);

                }
            }
        }
    
        ok[i][j] = true;
    }

    return dp[i][j];
}

int main(){
    optimize;

    int n;

    while(cin >> n && n){

        int x, bitmask = 0, ans;

        for(int i = 0; i < n; i++){
            cin >> x;
            bitmask |= (1 << (x - 1));
        }

        ans = solve(bitmask, 0);

        cout << (ans > 0 ? "Andy wins" : (ans < 0 ? "Ralph wins" : "Draw")) << "\n";
    }

    return 0;   
}
