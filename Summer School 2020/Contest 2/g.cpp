#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

long double dp[151][151];
bool ok[151][151];
long double v[151];
int w[151];

long double solve(int i, int j, int n){
    if(j <= 0) return 1;
    if(i >= n) return 0;
    if(!ok[i][j]) ok[i][j] = (dp[i][j] = max(solve(i + 1, j - w[i], n) * v[i] , solve(i + 1, j, n))) + 1; 
    return dp[i][j];
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(ok, 0, sizeof(ok));
        for(int i = 0; i < n; i++){
            cin >> w[i] >> v[i];
            v[i] /= 100.0;
        }
        cout << setprecision(6) << fixed << solve(0, 76, n) * 100.0 << endl;        
    }
}