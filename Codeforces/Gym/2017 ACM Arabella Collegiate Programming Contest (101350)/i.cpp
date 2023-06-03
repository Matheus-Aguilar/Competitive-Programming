#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

const char c[] = {'A','H','I','M','O','T','U','V','W','X','Y'};

int n;
string s;

vector<vector<bool>> dp, ok;

bool valid(char x){
    for(int i = 0; i < 11; i++){
        if(c[i] == x){
            return true;
        }
    }
    return false;
}

bool solve(int i, int j){
    if(i > j)
        return true;
    if(i == j)
        return valid(s[i]);
    if(!ok[i][j]){
        ok[i][j] = true;
        if(!valid(s[i]) || !valid(s[j]) || s[i] != s[j]){
            dp[i][j] = false;
        } else {
            dp[i][j] = solve(i + 1, j - 1);
        }
    }
    return dp[i][j];
}

int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        cin >> s;
        n = s.size();

        ok.assign(n, vector<bool>(n, false));
        dp.assign(n, vector<bool>(n, false));
    
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j)){
                    ans = max(ans, j - i + 1);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}