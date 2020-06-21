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

int n, m;
int adj[MAXN][MAXN];

int dijkstra(int s, int t){
    int dist[MAXN];
    bool visit[MAXN];

    ms(dist, INF);
    ms(visit, false);
    
    dist[s] = 0;
    while(!visit[t]){
        int u = -1;
        for(int i = 0; i < n; i++){
            if(!visit[i] && (u == -1 || dist[u] > dist[i]))
                u = i;
        }
        visit[u] = true;
        for(int i = 0; i < n; i++)
            dist[i] = min(dist[i], dist[u] + adj[u][i]);
    }
    return dist[t];
}

int main(){
    optimize;

    ms(adj, INF);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u - 1][v - 1] = adj[v - 1][u - 1] = c;
    }

    cout << dijkstra(0, n - 1) << "\n";
    
    return 0;   
}
