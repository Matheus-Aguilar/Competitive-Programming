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

string s, ans = "";

int n, k, pot[MAXN];
bool dp[MAXN][MAXN];

bool solve(int i, int j){
    
    if(i == n)
        return j == 0;

    if(!dp[i][j]){

        if(s[i] == '?'){
            for(int d = 0; d <= 9; d++){
                
                if(i == 0 && d == 0) continue;
                
                if(solve(i + 1, (j + pot[n - i - 1] * d) % k)){
                    ans[i] = (d + '0');
                    return true;
                }
            }
        }
        else{
            int d = (s[i] - '0');
            return solve(i + 1, (j + pot[n - i - 1] * d) % k);
        }

        dp[i][j] = true;
    }
    
    return false;
}

int main(){
    optimize;

    cin >> n >> k >> s;

    if(n == 1 && s == "?"){
        cout << 0 << "\n";
        return 0;
    }
    
    if(n > 1 && s[0] == '0'){
        cout << -1 << "\n";
        return 0;
    }

    ans = s;
    
    pot[0] = 1 % k;

    for(int i = 1; i < n; i++)
        pot[i] = (10 * pot[i - 1]) % k;

    if(solve(0, 0)){
        cout << ans << "\n";
    }
    else{
        cout << -1 << "\n";
    }

    return 0;   
}
