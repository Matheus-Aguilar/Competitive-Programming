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
    queue<int> q;
    q.push(start);
    fill(all(dist), INF);
    dist[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i:adj[cur]){
            if(dist[i] == INF){
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }
}

int main(){
    optimize;
    
    int n, m, k;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<vector<int>> gr(n);
    vector<int> dist(n);

    while(m--){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        gr[v - 1].push_back(u - 1);
    }

    cin >> k;
    vector<int> path(k);
    for(int i = 0; i < k; i++){
        cin >> path[i];
        path[i]--;
    }
    
    bfs(path.back(), gr, dist);
    
    int minimum = 0, maximum = 0;
    for(int i = 0; i < k - 1; i++){
        bool isShort = true;
        bool hasEqual = false;
        for(int j:g[path[i]]){
            if(dist[path[i + 1]] > dist[j]){
                isShort = false;
                break;
            }
            else if(dist[path[i + 1]] == dist[j] && path[i + 1] != j){
                hasEqual = true;
            }
        }

        if(!isShort)
            minimum++, maximum++;
        else if(hasEqual)
            maximum++;
    }

    cout << minimum << " " << maximum << "\n";

    return 0;   
}
