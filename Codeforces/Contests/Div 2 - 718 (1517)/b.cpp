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
        int n, m;
        cin >> n >> m;

        vector<vector<ll>> b(n, vector<ll>(m));

        vector<pair<ll, pair<int, int>>> path(n * m);

        vector<int> check(m);
        vector<vector<int>> run(n, vector<int>(m, -1));

        vector<vector<ll>> ans(n, vector<ll>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> b[i][j]; 
                path[i * m + j].first = b[i][j];
                path[i * m + j].second = make_pair(i, j);
            }
        }

        sort(all(path));

        for(int i = 0; i < m; i++){
            pair<int, int> p = path[i].second;
            run[p.first][p.second] = i;
            check[i] = p.first;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0, pos = 0; j < m; j++){
                if(check[j] == i)
                    continue;
                while(pos < m && run[i][pos] != -1)
                    pos++;
                run[i][pos] = j;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][run[i][j]] = b[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << ans[i][j] << " \n"[j==m-1];
            }
        }
    }
    
    return 0;   
}
