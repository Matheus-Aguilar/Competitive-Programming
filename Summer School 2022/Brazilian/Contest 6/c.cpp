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
#define MAXN 11000

using namespace std;

int n, dist1[MAXN], dist2[MAXN];
vector<int> adj[MAXN];

void bfs(int u, int p, int dist[]){
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v != p){
            dist[v] = dist[u] + 1;
            bfs(v, u, dist);
        }
    }
}

void bfs(int root, int dist[]){
    dist[root] = 0;
    bfs(root, -1, dist);
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1, dist1);

    int best = 1;

    for(int i = 2; i <= n; i++){
        if(dist1[best] < dist1[i]){
            best = i;
        }
    }

    bfs(best, dist2);

    int ans = 0;

    for(int i = 1; i <= n; i++){
        ans = max(ans, dist2[i]);
    }

    cout << ans << "\n";
    
    return 0;   
}
