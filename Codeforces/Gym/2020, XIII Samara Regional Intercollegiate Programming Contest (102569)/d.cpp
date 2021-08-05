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
#define MAXN 200200

using namespace std;

int n, m, dist[MAXN], nxt[MAXN];
char val[MAXN];
bool visit[MAXN];
vector<pair<int, char>> adj[MAXN];

typedef pair<pair<int, char>, pair<int, int>> Node;

void bfs(int source){
    
    ms(dist, INF);
    
    dist[source] = 0;
    nxt[source] = -1;
    val[source] = '$';

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.emplace(make_pair(dist[source], val[source]), make_pair(0, source));

    int cont = 0;

    while(!pq.empty()){
        
        Node node = pq.top();
        pq.pop();

        int u = node.second.second;
        cont++;

        if(visit[u]) continue;
        visit[u] = true;

        for(int i = 0; i < adj[u].size(); i++){
            
            int v = adj[u][i].first;
            char c = adj[u][i].second;

            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                val[v] = c;
                nxt[v] = u;
                pq.emplace(make_pair(dist[v], val[v]), make_pair(cont, v));
            }
            else if(dist[v] == dist[u] + 1 && val[v] > c){
                dist[v] = dist[u] + 1;
                val[v] = c;
                nxt[v] = u;
                pq.emplace(make_pair(dist[v], val[v]), make_pair(cont, v));
            }
        }
    }
}

int main(){
    optimize;

    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v;
        char c;

        cin >> u >> v >> c;

        adj[u - 1].emplace_back(v - 1, c);
        adj[v - 1].emplace_back(u - 1, c);
    }

    bfs(n - 1);

    int u = 0;
    vector<int> path;
    string s = "";

    do{
        path.push_back(u + 1);
        s += val[u];
        u = nxt[u];
    } while(u != -1);

    s.pop_back();

    cout << (int) path.size() - 1 << "\n";

    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " \n"[i+1==path.size()];
    
    cout << s << "\n";

    return 0;   
}
