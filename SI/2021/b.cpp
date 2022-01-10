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
#define MAXN 30
#define MAXP 5001000

using namespace std;

int p, t1, t2;
int X1[MAXN], X2[MAXN], Y1[MAXN], Y2[MAXN];

int dp[MAXP];

int solve(int u){

    if(u <= 0) 
        return 0;
    if(dp[u] == -1){

        int ans = u;

        for(int i = 0; i < t1; i++){
            if(u >= Y1[i]){

                int intdisc = u * X1[i];
                double disc = intdisc / 100.0;
                int val = u - (int) disc;

                if(val < u)
                    ans = min(ans, solve(val));
            }
        }

        for(int i = 0; i < t2; i++){
            if(u >= Y2[i]){
                int val = u - X2[i];

                if(val < u)
                    ans = min(ans, solve(val));
            }
        }

        dp[u] = max(ans, 0);
    }
    return dp[u];
}

int main(){
    optimize;

    ms(dp, -1);

    int a, b;
    char aux;
    cin >> a >> aux >> b;

    p = 100 * a + b;

    cin >> t1 >> t2;

    for(int i = 0; i < t1; i++){
        cin >> X1[i] >> Y1[i];
        Y1[i] *= 100;
    }

    for(int i = 0; i < t2; i++){
        cin >> X2[i] >> Y2[i];
        X2[i] *= 100;
        Y2[i] *= 100;
    }
    
    int ans = solve(p);

    cout << ans / 100;
    cout << ".";
    
    if(ans % 100 < 10)
        cout << '0';
    
    cout << ans % 100 << "\n";

    return 0;   
}
