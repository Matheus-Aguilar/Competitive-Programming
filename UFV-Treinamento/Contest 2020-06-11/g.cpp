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

void bfs(vector<vector<int>> &adj, vector<int> &dist){
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    optimize;

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> dist(n, -1);
    vector<int> cont(n, 0);

    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        adj[x - 1].push_back(i);
    }

    bfs(adj, dist);
    
    int ans = 0;
    
    for(int i = 0; i < n; i++)
        cont[dist[i]]++;
    
    for(int i = 0; i < n; i++)
        ans += (cont[i] % 2);

    cout << ans << "\n";

    return 0;   
}
