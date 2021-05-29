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

int n, m, t;

void bfs(vector<pii> &source, vector<vector<ll>> &cycle){
    queue<pii> q;
    for(int i = 0; i < source.size(); i++){
        q.push(source[i]);
        cycle[source[i].fi][source[i].se] = 0;
    }

    while(!q.empty()){
        pii u = q.front();
        q.pop();
        if(u.fi > 0 && cycle[u.fi - 1][u.se] == INFLL){
            q.push(pii(u.fi - 1, u.se));
            cycle[u.fi - 1][u.se] = cycle[u.fi][u.se] + 1;
        }
        if(u.fi < n - 1 && cycle[u.fi + 1][u.se] == INFLL){
            q.push(pii(u.fi + 1, u.se));
            cycle[u.fi + 1][u.se] = cycle[u.fi][u.se] + 1;
        }
        if(u.se > 0 && cycle[u.fi][u.se - 1] == INFLL){
            q.push(pii(u.fi, u.se - 1));
            cycle[u.fi][u.se - 1] = cycle[u.fi][u.se] + 1;
        }
        if(u.se < m - 1 && cycle[u.fi][u.se + 1] == INFLL){
            q.push(pii(u.fi, u.se + 1));
            cycle[u.fi][u.se + 1] = cycle[u.fi][u.se] + 1;
        }
    }
}

int main(){
    optimize;
    
    cin >> n >> m >> t;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        char aux;
        for(int j = 0; j < m; j++){
            cin >> aux;
            grid[i][j] = (int)(aux - '0');
        }
    }
    
    vector<pii> source;
    vector<vector<ll>> cycle(n, vector<ll>(m, INFLL));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i > 0 && grid[i - 1][j] == grid[i][j])
                source.push_back(pii(i, j));
            else if(i < n - 1 && grid[i + 1][j] == grid[i][j])
                source.push_back(pii(i, j));
            else if(j > 0 && grid[i][j - 1] == grid[i][j])
                source.push_back(pii(i, j));
            else if(j < m - 1 && grid[i][j + 1] == grid[i][j])
                source.push_back(pii(i, j));
        }
    }

    bfs(source, cycle);

    while(t--){
        int x, y;
        ll p, c;
        cin >> x >> y >> p;
        c = cycle[x - 1][y - 1];

        if(p < c)
            cout << grid[x - 1][y - 1] << "\n";
        else{
            if((p - c) % 2 == 0)
                cout << grid[x - 1][y - 1] << "\n";
            else
                cout << (grid[x - 1][y - 1] ^ 1) << "\n";
        }
    }

    return 0;   
}
