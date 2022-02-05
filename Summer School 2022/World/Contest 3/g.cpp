#include<iostream>
#include<cstring>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 220

using namespace std;

string s1, s2, s3;

bool dp[MAXN][MAXN], ok[MAXN][MAXN];

bool solve(int i, int j){
    if(i == s1.size() && j == s2.size())
        return true;
    if(!ok[i][j]){

        int k = i + j;
        dp[i][j] = false;

        if(i < s1.size() && s1[i] == s3[k])
            dp[i][j] |= solve(i + 1, j);
        if(j < s2.size() && s2[j] == s3[k])
            dp[i][j] |= solve(i, j + 1);

        ok[i][j] = true;
    }
    return dp[i][j];
}

int main(){
    optimize;
    
    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        ms(ok, false);

        cin >> s1 >> s2 >> s3;

        cout << "Data set " << t << ": " << (solve(0, 0) ? "yes" : "no") << "\n";
    } 

    return 0;   
}
