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

int n, m, ord[MAXN], nxt[MAXN], ans[MAXN];
bool ok[MAXN], vis[MAXN];

vector<int> adj[MAXN];
set<int> s;

void solve(int x){

    //Copy elements of the original order
    for(int i = 0; i < x; i++){
        
        int u = ord[i];

        s.erase(u);
        vis[u] = true;

        for(int j = 0; j < adj[u].size(); j++){
            
            int v = adj[u][j];
            
            if(!vis[v]){
                vis[v] = true;
                s.insert(v);
            }
        }

        ans[i] = u + 1;
    }

    //Add upper_bound to solution
    ans[x] = nxt[x] + 1;

    s.erase(nxt[x]);
    vis[nxt[x]] = true;

    for(int j = 0; j < adj[nxt[x]].size(); j++){
            
        int v = adj[nxt[x]][j];
        
        if(!vis[v]){
            vis[v] = true;
            s.insert(v);
        }
    }

    //Greedly add remaining elements
    for(int i = x + 1; i < n; i++){
        int u = *s.begin();

        s.erase(u);
        vis[u] = true;

        for(int j = 0; j < adj[u].size(); j++){
            
            int v = adj[u][j];
            
            if(!vis[v]){
                vis[v] = true;
                s.insert(v);
            }
        }

        ans[i] = u + 1;
    }

    //Print solution
    for(int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];
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

    for(int i = 0; i < n; i++){
        cin >> ord[i];
        ord[i]--;
    }

    ok[0] = (ord[0] != n - 1);
    nxt[0] = ord[0] + 1;

    for(int i = 0; i < n; i++){
        
        int u = ord[i];

        if(s.upper_bound(u) != s.end()){
            ok[i] = true;
            nxt[i] = *s.upper_bound(u);
        }

        s.erase(u);
        vis[u] = true;

        for(int j = 0; j < adj[u].size(); j++){
            
            int v = adj[u][j];
            
            if(!vis[v]){
                vis[v] = true;
                s.insert(v);
            }
        }
    }

    ms(vis, false);
    s.clear();

    for(int i = n - 1; i >= 0; i--){
        if(ok[i]){
            solve(i);
            return 0;
        }
    }

    cout << -1 << "\n";

    return 0;   
}
