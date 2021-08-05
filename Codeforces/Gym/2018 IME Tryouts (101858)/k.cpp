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
#define MAXN 100100

using namespace std;

int n, m, dist[MAXN][3];
bool visit[MAXN][3];

vector<pii> adj[MAXN];

void dijkstra(int s){
    
    ms(dist, INF);
    dist[s][0] = 0;

    priority_queue<pair<int, pii>> pq;

    pq.emplace(-dist[s][0], make_pair(s, 0));

    while(!pq.empty()){
        int u = pq.top().second.first;
        int e = pq.top().second.second;

        pq.pop();

        if(visit[u][e]) continue;
        visit[u][e] = true;

        if(u == n) continue;

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            int c = (e + 1) % 3;

            if(dist[u][e] + w < dist[v][c]){
                dist[v][c] = dist[u][e] + w;
                pq.emplace(-dist[v][c], make_pair(v, c));
            }
        }
    }
}

int main(){
    optimize;

    cin >> n >> m;

    while(m--){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dijkstra(1);

    pair<int, string> op[3] = {{dist[n][0], "me"}, {dist[n][1], "Gon"}, {dist[n][2], "Killua"}};
    sort(op, op + 3);

    cout << op[0].second << "\n";
    cout << op[1].second << "\n";
    cout << op[2].second << "\n";
    
    return 0;   
}
