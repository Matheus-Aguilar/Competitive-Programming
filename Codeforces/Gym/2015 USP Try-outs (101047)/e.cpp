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
#define fi first
#define se second

using namespace std;

const int mov[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int bfs(vector<pii> &s, pii e, vector<vector<char>> &grid, int n, int m){
    
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<int>> vis(n, vector<int>(m, false));

    queue<pii> q;

    for(int i = 0; i < s.size(); i++){
        q.push(s[i]);
        vis[s[i].fi][s[i].se] = true;
        dist[s[i].fi][s[i].se] = 0;
    }

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = u.fi + mov[i][0];
            int y = u.se + mov[i][1];

            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#' && !vis[x][y]){
                dist[x][y] = dist[u.fi][u.se] + 1;
                vis[x][y] = true;
                q.emplace(x, y);
            }
        }
    }

    return dist[e.fi][e.se];
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, m, ds, df;
        vector<pii> s, f;
        pii e;
        cin >> n >> m;

        vector<vector<char>> grid(n, vector<char>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];

                if(grid[i][j] == 'S')
                    s.emplace_back(i, j);
                if(grid[i][j] == 'F')
                    f.emplace_back(i, j);
                if(grid[i][j] == 'E')
                    e = make_pair(i, j);
            }
        }

        df = bfs(f, e, grid, n, m);
        ds = bfs(s, e, grid, n, m);
    
        cout << (ds < df ? "Y" : "N") << "\n";
    }
    
    return 0;   
}
