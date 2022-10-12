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

int n, c[MAXN], e[MAXN], sz[MAXN], h[MAXN];
ll ans[MAXN], total[MAXN], cur[MAXN], sum = 0;
vector<pii> adj[MAXN];
vector<int> vec[MAXN];
bool first = true;

void precalc(int u, int p = -1){
    
    sz[u] = 1;
    total[c[u]]++;

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        if(v != p){
            e[v] = adj[u][i].second;
            precalc(v, u);
            sz[u] += sz[v];
            if(h[u] == -1 || sz[h[u]] < sz[v])
                h[u] = v;
        }
    }
}

void add(int u){
    if(first){
        cur[c[u]]++;
        for(int i = 1; i <= n; i++)
            sum += cur[i] * (total[i] - cur[i]);
        first = false;
    } else {
        sum -= cur[c[u]] * (total[c[u]] - cur[c[u]]);
        cur[c[u]]++;
        sum += cur[c[u]] * (total[c[u]] - cur[c[u]]);
    }
}

void rem(int u){
    sum -= cur[c[u]] * (total[c[u]] - cur[c[u]]);
    cur[c[u]]--;
    sum += cur[c[u]] * (total[c[u]] - cur[c[u]]);
}

void dfs(int u, int p = -1, bool keep = true){

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        if(v != p && v != h[u]){
            dfs(v, u, false);
        }
    }

    if(h[u] != -1){
        dfs(h[u], u, true);
    }

    swap(vec[u], vec[h[u]]);

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        if(v != p && v != h[u]){
            for(int j = 0; j < vec[v].size(); j++){
                add(vec[v][j]);
                vec[u].push_back(vec[v][j]);
            }
        }
    }

    add(u);
    vec[u].push_back(u);
    
    if(e[u] != -1){
        ans[e[u]] = sum;
    }

    if(!keep){
        for(int i = 0; i < vec[u].size(); i++){
            rem(vec[u][i]);
        }
    }
}

int main(){
    optimize;

    ms(e, -1);
    ms(h, -1);
    
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> c[i];
    
    for(int i = 0; i < n - 1; i++){
        
        int u, v;
        cin >> u >> v;
        
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    precalc(1);
    dfs(1);

    for(int i = 0; i < n - 1; i++)
        cout << ans[i] << " \n"[i==n-2];

    return 0;   
}
