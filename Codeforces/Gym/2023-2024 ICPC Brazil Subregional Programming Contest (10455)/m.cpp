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

using namespace std;

int n, adj[MAXN][MAXN], ans = 0;

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){

            bool ok = true;

            for(int k = 0; k < n; k++){
                if(i == k || j == k)
                    continue;
                int diff = adj[i][j] - adj[i][k] - adj[k][j];

                if(diff > 0){
                    cout << -1 << "\n";
                    return 0;
                }

                if(diff == 0){
                    ok = false;
                }
            }

            if(!ok)
                ans++;
        }
    }

    cout << ans << "\n";
    
    return 0;   
}
