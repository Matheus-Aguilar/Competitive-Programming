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
#define MAXN 100009

using namespace std;

/*
 * Dijkstra's Algorithm O(nlogn + m) - Macacario ITA
 */
 
vector<pii> adj[MAXN];
 
int dijkstra(int s, int t, int n, int dist[]) {
	for(int i = 1; i <= n; i++) dist[i] = INF;
	set<pii> pq;
	dist[s] = 0;
	pq.insert(pii(0, s));
	while(!pq.empty()) {
		int u = pq.begin()->second;
		pq.erase(pq.begin());
		for(int i=0; i<(int)adj[u].size(); i++) {
			int v = adj[u][i].second;
			int w = adj[u][i].first;
			if (dist[v] > dist[u] + w) {
				pq.erase(pii(dist[v], v));
				dist[v] = dist[u] + w;
				pq.insert(pii(dist[v], v));
			}
		}
	}
	return dist[t];
}

int dist[MAXN], n, m, k;

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        cin >> n >> m >> k;

        for(int i = 0; i < n; i++){
            int u, v, c;
            cin >> u >> v >> c;

            adj[u].emplace_back(c, v);
            adj[v].emplace_back(c, u);
        }

        cout << fixed << setprecision(9) << (double) min(n * k, dijkstra(1, n, n, dist)) << "\n";
    }
    
    return 0;   
}
