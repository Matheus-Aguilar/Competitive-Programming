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
#define MAXN 301

using namespace std;

bool dp[MAXN][MAXN][MAXN];

int main(){
    optimize;

    int n, n1, n2, n3;
    cin >> n;

    if(n == 1){
        cin >> n1;
        cout << (n1 ? "BitLGM" : "BitAryo") << "\n";
    }
    else if(n == 2){
        cin >> n1 >> n2;
        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < MAXN; j++){
                if(!dp[i][j][0]){
                    for(int k = 1; k < MAXN; k++){
                        if(i + k < MAXN) 
                            dp[i + k][j][0] = true;
                        if(j + k < MAXN) 
                            dp[i][j + k][0] = true;
                        if(i + k < MAXN && j + k < MAXN)
                            dp[i + k][j + k][0] = true;
                    }
                }
            }
        }
        cout << (dp[n1][n2][0] ? "BitLGM" : "BitAryo") << "\n";
    }
    if(n == 3){
        cin >> n1 >> n2 >> n3;
        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < MAXN; j++){
                for(int k = 0; k < MAXN; k++){
                    if(!dp[i][j][k]){
                        for(int l = 1; l < MAXN; l++){
                            if(i + l < MAXN) 
                                dp[i + l][j][k] = true;
                            if(j + l < MAXN) 
                                dp[i][j + l][k] = true;
                            if(k + l < MAXN) 
                                dp[i][j][k + l] = true;
                            if(i + l < MAXN && j + l < MAXN && k + l < MAXN)
                                dp[i + l][j + l][k + l] = true;
                        }
                    }
                }
            }
        }
        cout << (dp[n1][n2][n3] ? "BitLGM" : "BitAryo") << "\n";
    }
    return 0;   
}
