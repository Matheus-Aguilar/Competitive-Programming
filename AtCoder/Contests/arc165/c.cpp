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

int n, e, c[MAXN];
vector<pii> adj[MAXN];

bool bipartite(int u, ll x){
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].second;
        int w = adj[u][i].first;

        if(w >= x)
            continue;
        if(c[v] == -1){
            c[v] = (c[u] == 1 ? 0 : 1);
            if(!bipartite(v, x))
                return false;
        }
        if(c[u] == c[v])
            return false;
    }
    return true;
}

bool check(ll x){
    ms(c, -1);
    
    for(int i = 0; i < n; i++){
        if(c[i] == -1){
            c[i] = 0;
            if(!bipartite(i, x)){
                return false;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(adj[i].size() >= 2 && adj[i][0].first + adj[i][1].first < x){
            return false;
        }
    }

    return true;
}

int main(){
    optimize;
    
    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(w, v - 1);
        adj[v - 1].emplace_back(w, u - 1);
    }

    for(int i = 0; i < n; i++)
        sort(adj[i].begin(), adj[i].end());

    ll l = 0, r = INFLL;

    while(l < r){
        ll m = l + (r - l + 1) / 2;
        if(check(m))
            l = m;
        else
            r = m - 1;
    }

    cout << l << "\n";

    return 0;   
}
