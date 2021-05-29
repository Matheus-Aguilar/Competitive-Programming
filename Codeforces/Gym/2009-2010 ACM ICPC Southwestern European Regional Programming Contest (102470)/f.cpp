#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<ll, ll>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 1009

using namespace std;

int dist[MAXN], N;
vector<pii> adj[MAXN];
bool hasNegativeWeightCycle = false;
bool isGrave[MAXN];
bool isHole[MAXN];

//O(VE)
int bellmanford(int s, int t){
	
    memset(dist, INF, sizeof(dist));
	dist[s] = 0;

    int v, w;

	for (int i = 0; i < N; i++) {
		for (int u = 0; u < N; u++) {
			for (int j = 0; j < (ll)adj[u].size(); j++) {
				v = adj[u][j].first;
				w = adj[u][j].second;
                if (i==N-1 && dist[v] > dist[u] + w && dist[u] != INF)
					hasNegativeWeightCycle = true;
				else if(dist[u] != INF)
                    dist[v] = min(dist[v], dist[u] + w);
            }
		}
	}
    
	return dist[t];
}

int main(){
    optimize;
    
    int w, h, g, e;
    while(cin >> w >> h && w && h){
        N = w * h;

        cin >> g;

        for(int i = 0; i < g; i++){
            int x, y;
            cin >> x >> y;
            isGrave[h * x + y] = true;
        }


        cin >> e;

        for(int i = 0; i < e; i++){
            int x1, y1, x2, y2, t;
            cin >> x1 >> y1 >> x2 >> y2 >> t;
            isHole[h * x1 + y1] = true;
            adj[h * x1 + y1].emplace_back(h * x2 + y2, t);
        }

        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                if(!isHole[h * i + j] && !isGrave[h * i + j] && h * i + j != w * h - 1){
                    if(i < w - 1 && !isGrave[h * (i + 1) + j])
                        adj[h * i + j].emplace_back(h * (i + 1) + j, 1);
                    if(j < h - 1 && !isGrave[h * i + j + 1])
                        adj[h * i + j].emplace_back(h * i + j + 1, 1);
                    if(i > 0 && !isGrave[h * (i - 1) + j])
                        adj[h * i + j].emplace_back(h * (i - 1) + j, 1);
                    if(j > 0 && !isGrave[h * i + j - 1])
                        adj[h * i + j].emplace_back(h * i + j - 1, 1);
                }
            }
        }

        int ans = bellmanford(0, w * h - 1);

        if(hasNegativeWeightCycle)
            cout << "Never" << "\n";
        else if(ans == INF)
            cout << "Impossible" << "\n";
        else
            cout << ans << "\n";

        hasNegativeWeightCycle = false;
        for(int i = 0; i < N; i++){
            adj[i].clear();
            isHole[i] = isGrave[i] = false;
        }
    }

    return 0;   
}
