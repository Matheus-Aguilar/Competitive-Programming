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

int n, m, k;
vector<vector<pii>> adj;
vector<int> p;

int dijkstra(){
    set<pair<pii, int>> pq;
    vector<pii> dist(n);

    for(int i = 0; i < n; i++)
        dist[i] = pii(INF, INF);
    for(int i = 0; i < k; i++){
        dist[p[i]] = pii(0, 0);
        pq.insert(make_pair(dist[p[i]], p[i]));
    }

    while(!pq.empty()){
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            if(dist[v].second >= dist[u].first + adj[u][i].second){
                pq.erase(make_pair(dist[v], v));
                dist[v].first = dist[v].second;
                dist[v].second = dist[u].first + adj[u][i].second;
                pq.insert(make_pair(dist[v], v));
            }
            else if(dist[v].first >= dist[u].first + adj[u][i].second){
                pq.erase(make_pair(dist[v], v));
                dist[v].first = dist[u].first + adj[u][i].second;
                pq.insert(make_pair(dist[v], v));
            }
        }
    }

    return dist[0].first;
}

int main(){
    optimize;

    cin >> n >> m >> k;

    adj.resize(n);
    p.resize(k);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(pii(v, c));
        adj[v].push_back(pii(u, c));
    }

    for(int i = 0; i < k; i++)
        cin >> p[i];
    
    cout << dijkstra() << "\n";

    return 0;   
}
