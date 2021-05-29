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

vector<int> g[MAXN];
vector<int> gr[MAXN];

int vis[MAXN];
int visr[MAXN];

int t = 1;

set<pii> e;

void dfs1(int u){
    
    vis[u] = t;
    
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(vis[v] != t){
            e.erase(pii(u, v));
            dfs1(v);
        }
    }
}

void dfs2(int u){
    
    visr[u] = t;
    
    for(int i = 0; i < gr[u].size(); i++){
        int v = gr[u][i];
        if(visr[v] != t){
            e.erase(pii(v, u));
            dfs2(v);
        }
    }
}

int main(){
    optimize;

    int T;
    cin >> T;

    while(t <= T){
        int n, m;
        cin >> n >> m;

        for(int i = 1; i <= n; i++)
            g[i].clear(), gr[i].clear();

        e.clear();
    
        for(int i = 0; i < m; i++){
            
            int u, v;
            cin >> u >> v;
            
            g[u].push_back(v);
            gr[v].push_back(u);
            
            e.insert(pii(u, v));
        }

        dfs1(1);
        dfs2(1);

        set<pii>::iterator it = e.begin();

        while(m != 2 * n){
            cout << it->first << " " << it->second << "\n";
            it++, m--;
        }

        t++;
    }
    
    return 0;   
}
