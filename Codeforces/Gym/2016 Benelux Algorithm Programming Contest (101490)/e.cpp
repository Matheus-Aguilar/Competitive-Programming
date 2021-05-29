#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<long long, long long>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 10000

using namespace std;

int N, M, X;

vector<pii> adj[MAXN];
ll dist[MAXN], best, maxDist;
priority_queue<pii> pq;

ll dijkstra(int s, int t, int m = INF){
    
    ms(dist, INF);
    dist[s] = 0;

    pq.emplace(-dist[s], s);

    while(!pq.empty()){
        
        int u = pq.top().second;
        pq.pop();

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(w <= m && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.emplace(-dist[v], v);
            }
        }
    }

    return dist[t];
}

bool check(int m){
    ll res = dijkstra(0, N - 1, m);
    return res <= maxDist;
}

int binSearch(int l, int r){
    
    while(l < r){
        int m = l + (r - l) / 2;

        if(check(m))
            r = m;
        else
            l = m + 1;
    }

    return l;
}

int main(){
    optimize;

    cin >> N >> M >> X;

    for(int i = 0; i < M; i++){
        int u, v, t;
        cin >> u >> v >> t;

        adj[u - 1].emplace_back(v - 1, t);
        adj[v - 1].emplace_back(u - 1, t);
    }

    best = dijkstra(0, N - 1);
    maxDist = (best * (X + 100LL)) / 100LL;

    cout << binSearch(0, INF) << "\n";
    
    return 0;   
}