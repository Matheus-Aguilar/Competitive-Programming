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

int w, h;

const pii moves[] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

void bfs(vector<pii> &s, vector<vector<int>> &dist, vector<string> &grid){
    
    queue<pii> q;
    
    for(int i = 0; i < s.size(); i++){
        dist[s[i].fi][s[i].se] = 0;
        q.push(s[i]);
    }

    while(!q.empty()){
        
        pii u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            pii v = pii(u.fi + moves[i].fi, u.se + moves[i].se);

            if(v.fi >= 0 && v.se >= 0 && v.fi < h && v.se < w && grid[v.fi][v.se] == '.' && dist[v.fi][v.se] == INF){
                dist[v.fi][v.se] = dist[u.fi][u.se] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        cin >> w >> h;

        vector<string> grid(h);

        for(int i = 0; i < h; i++)
            cin >> grid[i];
        
        vector<vector<int>> dist1(h, vector<int>(w, INF));
        vector<vector<int>> dist2(h, vector<int>(w, INF));
    
        vector<pii> s1, s2;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == '@'){
                    s1.emplace_back(i, j);
                } 
                else if(grid[i][j] == '*'){
                    s2.emplace_back(i, j);
                }
            }
        }

        bfs(s1, dist1, grid);
        bfs(s2, dist2, grid);

        int ans = INF;

        for(int i = 0; i < h; i++){
            if(dist1[i][0] < dist2[i][0]){
                ans = min(ans, dist1[i][0]);
            }
        }
        for(int i = 0; i < h; i++){
            if(dist1[i][w-1] < dist2[i][w-1]){
                ans = min(ans, dist1[i][w-1]);
            }
        }
        for(int i = 0; i < w; i++){
            if(dist1[0][i] < dist2[0][i]){
                ans = min(ans, dist1[0][i]);
            }
        }
        for(int i = 0; i < w; i++){
            if(dist1[h-1][i] < dist2[h-1][i]){
                ans = min(ans, dist1[h-1][i]);
            }
        }

        if(ans == INF) 
            cout << "IMPOSSIBLE" << "\n"; 
        else 
            cout << ans + 1 << "\n";
    }

    return 0;   
}
