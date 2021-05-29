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

void bfs(vector<int> &start, vector<vector<int>> &adj, vector<int> &dist){
    queue<int> q;
    vector<bool> v(adj.size(), false);
    for(int i = 0; i < start.size(); i++){
        q.push(start[i]);
        v[start[i]] = true;
        dist[start[i]] = 1;
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < adj[cur].size(); i++){
            if(!v[adj[cur][i]]){
                q.push(adj[cur][i]);
                v[adj[cur][i]] = true;
                dist[adj[cur][i]] = dist[cur] + 1;
            }
        }
    }
}

int main(){
    optimize;
    
    int n;
    cin >> n;

    vector<int> start;
    vector<vector<int>> adj(n);
    vector<int> dist(n, -1);
    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        int prv = i - a[i];
        int nxt = i + a[i];
        if(prv >= 0){
            adj[prv].push_back(i);
            if(a[prv] % 2 != a[i] % 2)
                start.push_back(i);
        }
        if(nxt < n){ 
            adj[nxt].push_back(i);
            if(a[nxt] % 2 != a[i] % 2 && (start.empty() || start.back() != i))
                start.push_back(i);
        }
    }

    bfs(start, adj, dist);
    for(int i = 0; i < n; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;   
}
