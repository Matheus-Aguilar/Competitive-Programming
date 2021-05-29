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

int n, m, d, dist[MAXN], par[MAXN];
vector<pii> adj[MAXN];
vector<int> path;

bool check(int m){
    ms(par, -1);
    ms(dist, INF);

    queue<int> q;

    q.push(1);
    dist[1] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++){
            
            if(adj[u][i].second > m) continue;
            
            int v = adj[u][i].first;

            if(dist[v] == INF){
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }

    return dist[n] <= d;
}

int binSearch(int l, int r){
    
    while(l < r){
        int m = l + (r - l)/2;

        if(check(m))
            r = m;
        else
            l = m + 1;
    }

    return l;
}

int main(){
    optimize;

    cin >> n >> m >> d;

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
    }

    int best = binSearch(0, INF);

    if(check(best)){
        cout << dist[n] << "\n";

        int u = n;

        while(u != -1){
            path.push_back(u);
            u = par[u];
        }

        for(int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << " ";

        cout << "\n";
    }
    else{
        cout << -1 << "\n";
    }
    
    return 0;   
}
