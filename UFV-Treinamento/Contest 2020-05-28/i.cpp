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

bool bipartite(vector<vector<int>> &adj, vector<int> &color){
    stack<int> s;
    s.push(0);
    color[0] = 0;

    while(!s.empty()){
        int u = s.top();
        s.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(color[v] == -1){
                color[v] = !(color[u]);
                s.push(v);
            }
            else if(color[u] == color[v]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<pii> edges(m);
    vector<int> color(n, -1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = pii(u, v);
    }

    if(bipartite(adj, color)){
        cout << "YES" << "\n";
        for(int i = 0; i < m; i++)
            cout << color[edges[i].first];
        cout << "\n";
    }
    else
        cout << "NO" << "\n";
    
    return 0;   
}
