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

void bfs(int s, vector<int> &dist, vector<vector<int>> &adj){
    
    queue<int> q;
    
    q.push(s);
    dist[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(dist[v] == INF){
                dist[v] = dist[u] + 1;
                q.push(v);    
            }
        }
    }
}

int main(){
    optimize;

    int n, m, a, b;

    cin >> n >> m >> a >> b;

    vector<vector<int>> g(n + 1);
    vector<vector<int>> gr(n + 1);
    vector<int> dist1(n + 1, INF);
    vector<int> dist2(n + 1, INF);
    vector<int> dist3(n + 1, INF);

    while(m--){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        gr[y].push_back(x);
    }

    bfs(0, dist1, g);
    bfs(a, dist2, gr);
    bfs(b, dist3, gr);

    int ans = INF;

    for(int i = 0; i <= n; i++)
        ans = min(ans, dist1[i] + dist2[i] + dist3[i]);

    cout << ans << "\n";

    return 0;   
}
