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
#define MAXN 1010

using namespace std;

string ans, s;

int n, pot[MAXN];
bool dp[MAXN][MAXN];

bool solve(int i, int j){
    if(i == s.size())
        return j == 0;
    
    if(!dp[i][j]){

        if(s[i] != '?'){

            int val = (s[i] - '0');

            return solve(i + 1, (j + pot[s.size() - i - 1] * val) % n);
        }

        for(int k = 0; k <= 9; k++){
            
            if(i == 0 && k == 0) continue;

            if(solve(i + 1, (j + pot[s.size() - i - 1] * k) % n)){
                ans[i] = (k + '0');
                return true;
            }
        }

        dp[i][j] = true;
    }

    return false;
}

int main(){
    optimize;

    cin >> s >> n;

    pot[0] = 1 % n;

    for(int i = 1; i < s.size(); i++)
        pot[i] = (10 * pot[i - 1]) % n;

    ans = s;

    if(solve(0, 0)){
        cout << ans << "\n";
        return 0;
    }

    cout << "*" << "\n";

    return 0;   
}
