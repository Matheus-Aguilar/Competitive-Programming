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

int n, m, dist[MAXN];
vector<int> adj[MAXN];

void bfs(int s){

    ms(dist, INF);
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()){

        int u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];

            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
}

int main(){
    optimize;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    bfs(0);

    int D = *max_element(dist, dist + n);

    if(D == INF){
        cout << -1 << "\n";
        return 0;
    }

    cout << (int) ceil(log2(D)) + 1 << "\n";
    
    return 0;   
}
