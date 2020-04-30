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

void bfs(int start, vector<vector<int>> &adj, vector<int> &dist){
    
    vector<bool> visit(adj.size(), false);
    
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    visit[start] = true;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(!visit[v]){
                visit[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;

        --a, --b, --c;

        vector<vector<int>> adj(n);
        vector<int> w(m);
        vector<int> distA(n);
        vector<int> distB(n);
        vector<int> distC(n);
        vector<ll> prefix(m + 1);
    
        for(int i = 0; i < m; i++)
            cin >> w[i];
        sort(all(w));

        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        prefix[0] = 0;
        for(int i = 0; i < m; i++)
            prefix[i + 1] =  prefix[i] + w[i];

        bfs(a, adj, distA);
        bfs(b, adj, distB);
        bfs(c, adj, distC);
    
        ll ans = INFLL;
        for(int i = 0; i < n; i++)
            if(distA[i] + distB[i] + distC[i] <= m)
                ans = min(ans, prefix[distA[i] + distB[i] + distC[i]] + prefix[distB[i]]);
        cout << ans << "\n";
    }
    
    return 0;   
}
