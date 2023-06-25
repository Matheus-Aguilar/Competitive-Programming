#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 1100

using namespace std;

int n, k;
int g[MAXN][MAXN];

int main(){

    optimize;

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> g[i][j];
        }
    }

    int ans = 0;

    for(int i = 1; i + k - 1 <= n; i++){
        for(int j = 1; j + k - 1 <= n; j++){
            int d1 = g[i][j];
            int d2 = g[i + k - 1][j];
            int d3 = g[i][j + k - 1];
            int d4 = g[i + k - 1][j + k - 1];

            if(d1 == d2 && d1 == d3 && d1 == d4)
                ans++;        
        }
    }

    cout << ans << "\n";

    return 0;
}