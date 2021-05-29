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

void dijkstra(int u, int n, vector<int> &edges, vector<ll> &dist){
    
    vector<bool> visit(n, false);
    
    dist[u] = 0;

    while(u != -1){
        
        visit[u] = true;

        for(int i = 0; i < n; i++){
            int v = (u + i) % n;
            dist[v] = min(dist[v], dist[u] + edges[i]);
        }

        u = -1;

        for(int i = 0; i < n; i++){
            if(!visit[i] && (u == -1 || dist[u] > dist[i])){
                u = i;
            }
        }
    }
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(all(a));
        
        vector<int> edges(a[0], INF);
        vector<ll> dist(a[0], INF);

        for(int i = 0; i < n; i++)
            edges[a[i] % a[0]] = min(edges[a[i] % a[0]], a[i]);
        
        dijkstra(0, a[0], edges, dist);

        ll ans = 0;

        for(int i = 0; i < a[0]; i++)
            ans = max(ans, dist[i] - a[0]);
        
        cout << (ans > 1000000 ? -1 : ans) << "\n";
    }
    
    return 0;   
}
