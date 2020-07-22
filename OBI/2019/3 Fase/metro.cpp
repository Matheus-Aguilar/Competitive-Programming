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

int bfs(vector<vector<int>> &adj, vector<int> &par, vector<int> &dist, int n, int s){
    dist[s] = 0, par[s] = s;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(par[u] != v){
                par[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return (max_element(all(dist)) - dist.begin());
}

int solve(vector<vector<int>> &adj, int n){
    vector<int> par(n), dist(n);
    int u = bfs(adj, par, dist, n, 0);
    int v = bfs(adj, par, dist, n, u);
    int w = v;
    while(dist[w] > dist[v]/2)
        w = par[w];
    return w;
}

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n);
    vector<vector<int>> b(m);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        a[v - 1].push_back(u - 1);
    }

    for(int i = 0; i < m - 1; i++){
        int u, v;
        cin >> u >> v;
        b[u - 1].push_back(v - 1);
        b[v - 1].push_back(u - 1);
    }

    int x = solve(a, n) + 1;
    int y = solve(b, m) + 1;
    
    cout << x << " " << y << "\n";

    return 0;   
}
