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

int n, m;
vector<pair<int, ll>> adjx[MAXN], adjy[MAXN];
ll x[MAXN], y[MAXN];
bool vis[MAXN];

void bfs(){

    x[0] = 0;
    y[0] = 0;
    vis[0] = true;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < adjx[u].size(); i++){
            
            int v = adjx[u][i].first;
            ll cx = adjx[u][i].second;
            ll cy = adjy[u][i].second;

            if(!vis[v]){
                vis[v] = true;
                x[v] = x[u] + cx;
                y[v] = y[u] + cy;
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
        ll cx, cy;
        cin >> u >> v >> cx >> cy;
        
        u--;
        v--;
        
        adjx[u].emplace_back(v, cx);
        adjy[u].emplace_back(v, cy);

        adjx[v].emplace_back(u, -cx);
        adjy[v].emplace_back(u, -cy);
    }
    
    bfs();

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cout << "undecidable" << "\n";
        } else {
            cout << x[i] << " " << y[i] << "\n";
        }
    }

    return 0;   
}
