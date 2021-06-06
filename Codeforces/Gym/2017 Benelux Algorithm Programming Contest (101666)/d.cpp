#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 100100

using namespace std;

int n, m;
ll dist[MAXN];
bool visit[MAXN];
vector<int> path;
vector<pll> adj[MAXN];

void dijkstra(int s){
    
    ms(dist, INF);
    dist[s] = 0;
    
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.emplace(dist[s], s);

    while(!pq.empty()){
        
        pll p = pq.top();
        pq.pop();

        int u = p.second;

        if(p.first > dist[u])
            continue;

        for(int i = 0; i < adj[u].size(); i++){
            
            int v = adj[u][i].first;
            ll  w = adj[u][i].second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

bool dfs(int u, int d){
    
    path.push_back(u);
    visit[u] = true;

    if(u == d) return true;

    int lock = -1;
    ll  cost = INFLL;

    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i].first;
        ll  w = adj[u][i].second;

        if(lock == -1 || cost > dist[v] + w){
            lock = v;
            cost = dist[v] + w;
        }
    }

    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i].first;
    
        if(!visit[v] && lock != v){
            if(dfs(v, d)){
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

int main(){
    optimize;

    cin >> n >> m;

    while(m--){
        
        int u, v, c;
        cin >> u >> v >> c;
        
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    
    dijkstra(1);

    if(dfs(0, 1)){
        cout << path.size() << " ";

        for(int i = 0; i < path.size(); i++)
            cout << path[i] << " \n"[i==path.size()-1];
    }
    else
        cout << "impossible" << "\n";

    return 0;   
}
