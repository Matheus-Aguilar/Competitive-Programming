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
#define MAXN 2100

using namespace std;

int n, k;
string nums[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
pii v[MAXN][10];
bool solved[MAXN][MAXN];
bool dp[MAXN][MAXN];
string ans = "";

bool solve(int i, int j){
    if(i == n){
        return j == k;
    }
    else if(j > k){
        return false;
    }
    else if(!solved[i][j]){
        dp[i][j] = false;
        for(int k = 0; k < 10 && !dp[i][j]; k++){
            dp[i][j] = solve(i + 1, j + v[i][k].second);
            if(dp[i][j]){
                ans += to_string(v[i][k].first);
            }
        }
        solved[i][j] = true;
    }
    return dp[i][j];
}

int calc(string &s, string &t){
    int sum = 0;
    for(int i = 0; i < 7; i++){
        if(t[i] == '0' && s[i] == '1')
            return INF;
        else if(t[i] == '1' && s[i] == '0')
            sum++;
    }
    return sum;
}

int main(){
    optimize;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 9; j >= 0; j--){
            v[i][9 - j] = pii(j, calc(s, nums[j]));
        }
    }

    bool ok = solve(0, 0);
    if(ok) reverse(all(ans));
    cout << (ok ? ans : "-1") << "\n";

    return 0;   
}
