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
#define MAXN 330

using namespace std;

int n, m, dist[MAXN];
bool vis[MAXN];
int adj[MAXN][MAXN], ans[MAXN][MAXN];

void dijkstra(int s, int bit, int pos){
    
    ms(dist, INF);
    ms(vis, false);

    dist[s] = 0;

    for(int i = 0; i < n; i++){
        int u = -1;

        for(int v = 0; v < n; v++){
            if(!vis[v] && (u == -1 || dist[v] < dist[u])){
                u = v;
            }
        }

        vis[u] = true;

        for(int v = 0; v < n; v++){
            if(u == s && ((v >> pos) & 1) == bit)
                continue;
            if(!vis[v])
                dist[v] = min(dist[v], dist[u] + adj[u][v]);
        }
    }
}

void solve(int s){
    for(int bit = 0; bit <= 1; bit++){
        for(int pos = 0; pos <= 9; pos++){
            dijkstra(s, bit, pos);
        
            for(int i = 0; i < n; i++){
                if(i != s && ((i >> pos) & 1) == bit && dist[i] < INF){
                    ans[s][i] = min(ans[s][i], dist[i]);
                }
            }
        }
    }
}

int main(){
    optimize;

    ms(adj, INF);
    ms(ans, INF);

    cin >> n >> m;

    vector<pii> edges(m);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u - 1][v - 1] = adj[v - 1][u - 1] = c;
        edges[i] = make_pair(u - 1, v - 1);
    }

    for(int i = 0; i < n; i++)
        solve(i);

    for(int i = 0; i < m; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        cout << (ans[u][v] == INF ? -1 : ans[u][v]) << "\n";
    }
    
    return 0;   
}
