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

int n, m, dist[100][100], v[100][100];
char g[100][100];
int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(){
    queue<pii> q;
    ms(dist, INF);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'L'){
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = u.first + moves[i][0];
            int y = u.second + moves[i][1];

            if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] == 'W') continue;

            if(dist[x][y] == INF){
                dist[x][y] = dist[u.first][u.second] + 1;
                q.emplace(x, y);
            }
        }
    }
}

void bfs(pii s){
    queue<pii> q;
    
    q.push(s);
    v[s.first][s.second] = true;

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = u.first + moves[i][0];
            int y = u.second + moves[i][1];

            if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] != 'L') continue;

            if(!v[x][y]){
                v[x][y] = true;
                q.emplace(x, y);
            }
        }
    }
}

void convert(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'C'){
                g[i][j] = (dist[i][j] == INF ? 'W' : 'L');
            }
        }
    }
}

int countCC(){
    
    ms(v, false);

    int cc = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'L' && !v[i][j]){
                cc++;
                bfs(make_pair(i, j));
            }
        }
    }

    return cc;
}

int main(){
    optimize;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    
    bfs();
    convert();
    
    cout << countCC() << "\n";

    return 0;   
}