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
#define MAXN 110
#define MAXA 2010

using namespace std;

int n, sum = 0, a[MAXN];
bool dp[MAXN][MAXA * MAXN], ok[MAXN][MAXA * MAXN];

bool solve(int i, int j){
    if(2 * j > sum)
        return false;
    if(i == n)
        return (2 * j == sum);
    if(!ok[i][j]){
        dp[i][j] = (solve(i + 1, j) || solve(i + 1, j + a[i]));
        ok[i][j] = true;
    }
    return dp[i][j];
}

int main(){
    optimize;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    bool k = solve(0, 0); //Check if is already solved

    if(!k)
        cout << 0 << "\n";
    else{
        cout << 1 << "\n";

        int pos = -1;

        while(pos == -1){
            
            for(int i = 0; i < n && pos == -1; i++){
                if(a[i] & 1)
                    pos = i;
                a[i] >>= 1;
            }
        
        }
    
        cout << pos + 1 << "\n";
    }

    return 0;   
}
