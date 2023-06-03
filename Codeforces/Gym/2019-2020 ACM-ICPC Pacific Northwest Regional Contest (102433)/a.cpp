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

int n;
ll dist[MAXN], distV[MAXN], ans[MAXN], par[MAXN], pe[MAXN], sz[MAXN], sum[MAXN], t[MAXN], total = 0;
vector<pii> adj[MAXN];

void precalc(int u, int p = -1){
    sz[u] = 1;
    sum[u] = t[u];
    dist[u] = 0;
    distV[u] = 0;

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        int w = adj[u][i].second;

        if(v != p){
            
            par[v] = u;
            pe[v] = w;
            
            precalc(v, u);
            
            sz[u] += sz[v];
            sum[u] += sum[v];
            dist[u] += dist[v] + sz[v] * w;
            distV[u] += distV[v] + sum[v] * w;
        }
    }
}

void calc(int u, int p = -1){
    
    if(p != -1){
        ll szC = n - sz[u];
        ll sumC = total - sum[u];
        ll distC = dist[p] - dist[u] - sz[u] * pe[u];
        ll distVC = distV[p] - distV[u] - sum[u] * pe[u];
        dist[u] += distC + szC * pe[u];
        distV[u] += distVC + sumC * pe[u]; 
    }

    ans[u] = t[u] * dist[u] + distV[u];

    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i].first;
        int w = adj[u][i].second;

        if(v != p){
            calc(v, u);
        }
    }
}

int main(){
    optimize;

    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> t[i];
        total += t[i];
    }
    
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);
    }

    precalc(0);
    calc(0);

    for(int i = 0; i < n; i++)
        cout << ans[i] << "\n";

    return 0;   
}
