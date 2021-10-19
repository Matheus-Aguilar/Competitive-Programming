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

int I, S, L, U;

vector<pii> adj[MAXN];
pii edges[MAXN];

bool visit[MAXN];
int dist[MAXN];

void dijkstra(int s){
    
    ms(dist, INF);
    dist[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(dist[s], s);

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(visit[u]) continue;
        visit[u] = true;

        for(int i = 0; i < adj[u].size(); i++){
            
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main(){
    optimize;

    cin >> I >> S >> L >> U;

    for(int i = 0; i < S; i++){
        int u, v, c;
        cin >> u >> v >> c;

        edges[i] = make_pair(u, v);

        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    dijkstra(0);

    int cont = 0;

    for(int i = 0; i < S; i++){

        int u = edges[i].first;
        int v = edges[i].second;

        if(2 * dist[u] < U || 2 * dist[v] < U){
            cont++;
        }
    }

    cout << cont << "\n";
    
    return 0;   
}
