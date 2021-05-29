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

const pii moves[4] = {pii(0, -1), pii(0, 1), pii(-1, 0), pii(1, 0)};

int n, m, d;
vector<vector<char>> grid;
vector<vector<int>> distS;
vector<vector<int>> distM;
vector<pii> mons;
pii s, f;

bool valid1(pii v){
    return (v.fi >= 0 && v.se >= 0 && v.fi < n && v.se < m && distM[v.fi][v.se] == INF);
}

void bfs1(){
    queue<pii> q;
    
    for(int i = 0; i < mons.size(); i++){
        distM[mons[i].fi][mons[i].se] = 0;
        q.push(mons[i]);
    }

    while(!q.empty()){
        pii u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            pii v = pii(u.fi + moves[i].fi, u.se + moves[i].se);
            if(valid1(v)){
                distM[v.fi][v.se] = distM[u.fi][u.se] + 1;
                q.push(v);
            }
        }
    }
}

bool valid2(pii v){
    return (v.fi >= 0 && v.se >= 0 && v.fi < n && v.se < m && distS[v.fi][v.se] == INF && distM[v.fi][v.se] > d);
}

void bfs2(){
    queue<pii> q;

    if(distM[s.fi][s.se] <= d) return;

    distS[s.fi][s.se] = 0;
    q.push(s);

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            pii v = pii(u.fi + moves[i].fi, u.se + moves[i].se);
            if(valid2(v)){
                distS[v.fi][v.se] = distS[u.fi][u.se] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    optimize;

    cin >> n >> m >> d;

    grid.assign(n, vector<char>(m));
    distS.assign(n, vector<int>(m, INF));
    distM.assign(n, vector<int>(m, INF));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S')
                s = pii(i, j);
            else if(grid[i][j] == 'F')
                f = pii(i, j);
            else if(grid[i][j] == 'M')
                mons.emplace_back(i, j);
        }
    }

    bfs1();
    bfs2();

    cout << (distS[f.fi][f.se] == INF ? -1 : distS[f.fi][f.se]) << "\n";

    return 0;   
}
