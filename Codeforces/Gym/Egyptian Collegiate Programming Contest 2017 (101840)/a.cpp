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

using namespace std;

int N, X, Y, K;
double p, q, dp[3010][51][51];
bool ok[3010][51][51];

double solve(int k, int x, int y){

    if(k == 0){
        if(x == Y && y == X)
            return 1.0;
        return 0.0;
    }

    if(!ok[k][x][y]){
    
        dp[k][x][y] = (1.0 - p) * solve(k - 1, x, y);
    
        if(X != Y){
            for(int i = 0; i < N - 1; i++){
                if((i == x && i + 1 == y) || (i == y && i + 1 == x)){
                    dp[k][x][y] += p * q * solve(k - 1, y, x);
                }
                else if(i == x){
                    dp[k][x][y] += p * q * solve(k - 1, i + 1, y);
                }
                else if(i + 1 == x){
                    dp[k][x][y] += p * q * solve(k - 1, i, y);
                }
                else if(i == y){
                    dp[k][x][y] += p * q * solve(k - 1, x, i + 1);
                }
                else if(i + 1 == y){
                    dp[k][x][y] += p * q * solve(k - 1, x, i);
                }
                else{
                    dp[k][x][y] += p * q * solve(k - 1, x, y);
                }
            }
        }
        else{
            for(int i = 0; i < N - 1; i++){
                if(i == x){
                    dp[k][x][y] += p * q * solve(k - 1, i + 1, i + 1);
                }
                else if(i + 1 == x){
                    dp[k][x][y] += p * q * solve(k - 1, i, i);
                }
                else{
                    dp[k][x][y] += p * q * solve(k - 1, x, y);
                }
            }
        }

        ok[k][x][y] = true;
    }

    return dp[k][x][y];
}

int main(){
    optimize;

    ifstream in("assessment.in");

    int T;
    in >> T;

    for(int t = 1; t <= T; t++){

        ms(ok, false);
        
        in >> N >> p >> X >> Y >> K;

        if(N == 1){
            cout << "Case " << t << ": " << fixed << setprecision(5) << 1.0 << "\n";    
            continue;
        }

        q = 1.0 / (N - 1);

        cout << "Case " << t << ": " << fixed << setprecision(5) << solve(K, X, Y) << "\n";
    }
    
    return 0;   
}
