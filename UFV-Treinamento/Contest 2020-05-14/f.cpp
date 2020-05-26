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

struct Edge{
    int u, v;
    ll f, c;
    Edge(int _u = -1, int _v = -1, int _f = 0, ll _c = 0): u(_u), v(_v), f(_f), c(_c){}
};

struct MinCostMaxFlow{
    vector<Edge> edge;
    vector<int> nxt;
    vector<int> first;
    vector<int> par;
    vector<ll> pot;
    vector<ll> dist;

    MinCostMaxFlow(int n){
        first.assign(n, -1);
        par.resize(n);
        pot.assign(n, 0);
        dist.resize(n);
    }
    void addEdge(int u, int v, int f, int c){
        edge.push_back(Edge(u, v, f, c));
        nxt.push_back(first[u]);
        first[u] = edge.size() - 1;

        edge.push_back(Edge(v, u, 0, -c));
        nxt.push_back(first[v]);
        first[v] = edge.size() - 1;
    }
    bool dijkstra(int s, int t){
        set<pii> pq;
        for(int i = 0; i < dist.size(); i++){
            dist[i] = INFLL;
            par[i] = -1;
        }
        dist[s] = 0;
        pq.insert(pii(dist[s], s));
        while(!pq.empty()){
            int u = pq.begin()->second;
            pq.erase(pq.begin());
            for(int i = first[u]; i != -1; i = nxt[i]){
                if(edge[i].f <= 0) continue;

                int v = edge[i].v;
                int c = edge[i].c;

			    if(dist[v] > dist[u] + c + pot[u] - pot[v]){
                    pq.erase(pii(dist[v], v));
                    dist[v] = dist[u] + c + pot[u] - pot[v];
                    pq.insert(pii(dist[v], v));
                    par[v] = i;
                }
            }
        }
        return dist[t] != INFLL;
    }
    pair<ll, ll> getMinCostMaxFlow(int s, int t, ll k = INFLL){
        ll minCost = 0, maxFlow = 0;
        while(maxFlow < k && dijkstra(s, t)){
            ll flow = INFLL;
            for(int i = t; i != s; i = edge[par[i]].u)
                flow = min(flow, edge[par[i]].f);
            for(int i = t; i != s; i = edge[par[i]].u){
                edge[par[i]].f -= flow;
                edge[par[i]^1].f += flow;
            }

            maxFlow += flow;
            minCost += flow * (dist[t] - pot[s] + pot[t]);
            
            for(int i = 0; i < pot.size(); i++)
                if(dist[i] != INFLL)
                    pot[i] += dist[i];
        }
        return make_pair(minCost, maxFlow);
    }
};

int main(){
    optimize;

    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    MinCostMaxFlow mcmf(n + 2);
    for(int i = 0; i < n; i++){
        mcmf.addEdge(n, i, 1, a[i]);
        mcmf.addEdge(i, n + 1, 1, b[i]);
        if(i < n - 1)
            mcmf.addEdge(i, i + 1, k, 0);
    }

    cout << mcmf.getMinCostMaxFlow(n, n + 1, k).first << "\n";
    
    return 0;   
}
