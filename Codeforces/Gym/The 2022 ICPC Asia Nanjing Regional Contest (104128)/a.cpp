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

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        int n, m, k;
        cin >> n >> m >> k;

        k = n * m - k;
        
        string s;
        cin >> s;

        int x = 0, y = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'U')
                x--;
            else if(s[i] == 'D')
                x++;
            else if(s[i] == 'L')
                y--;
            else
                y++;
        
            x1 = min(x1, x);
            x2 = max(x2, x);
            y1 = min(y1, y);
            y2 = max(y2, y);
        }

        x1 = -x1;
        x2 = n - x2 - 1;
        y1 = -y1;
        y2 = m - y2 - 1;

        if(x1 > x2 || y1 > y2){
            cout << (k == n * m ? n * m : 0) << "\n";
            continue;
        }

        k -= n * m - (x2 - x1 + 1) * (y2 - y1 + 1);

        vector<vector<int>> vis(n, vector<int>(m, 0));

        x = x1;
        y = y1;

        vis[x][y] = 1;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'U')
                x--;
            else if(s[i] == 'D')
                x++;
            else if(s[i] == 'L')
                y--;
            else
                y++;
            vis[x][y] = 1;
        }

        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sum[i][j] = vis[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int i0 = max(0, i - (x2 - x1));
                int j0 = max(0, j - (y2 - y1));

                int val = sum[i + 1][j + 1] - sum[i + 1][j0] - sum[i0][j + 1] + sum[i0][j0];
                if(val == k){
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
