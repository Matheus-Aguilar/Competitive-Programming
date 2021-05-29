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

void dijkstra(int s, int n, vector<pair<ll, int>> &edges, vector<ll> &dist){
    
    vector<bool> visit(n, false);
    priority_queue<pair<ll, int>> pq;
    
    dist[s] = 0;
    pq.emplace(-dist[s], s);

    while(!pq.empty()){
        
        int u = pq.top().second;
        pq.pop();

        if(visit[u])
            continue;

        visit[u] = true;

        for(int i = 0; i < edges.size(); i++){

            int v = (u + edges[i].second) % n;
            ll w = edges[i].first;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.emplace(-dist[v], v);
            }
        }
    }
}

int main(){
    optimize;

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));
    
    vector<int> md(a[0], INF);
    vector<ll> dist(a[0], INF);
    vector<pair<ll, int>> edges;

    for(int i = 0; i < n; i++)
        md[a[i] % a[0]] = min(md[a[i] % a[0]], a[i]);
    
    for(int i = 1; i < a[0]; i++){
        if(md[i] != INF){
            edges.emplace_back(md[i], i);
        }
    }
    
    dijkstra(0, a[0], edges, dist);

    int k;
    cin >> k;

    while(k--){
        int q;
        cin >> q;
        cout << (q < dist[q % a[0]] ? "NIE" : "TAK") << "\n";
    }
    
    return 0;   
}
