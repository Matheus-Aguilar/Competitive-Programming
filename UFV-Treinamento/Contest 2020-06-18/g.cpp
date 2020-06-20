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

int n;
ll dp[MAXN];
ll a[MAXN];
bool deleted[MAXN];
vector<pii> adj[MAXN];

void dfs(int u, int p){
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        int c = adj[u][i].second;
        if(v != p){
            dp[v] = max(dp[u] + c, 0LL);
            dfs(v, u);
        }
    }
}

void dfs(int u, int p, int &cont){
    cont++;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        if(v != p && !deleted[v])
            dfs(v, u, cont);
    }
}

void dfs(int source){
    dp[source] = 0;
    dfs(source, -1);
}

int main(){
    optimize;

    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n; i++){
        int v, c;
        cin >> v >> c;
        adj[i].push_back(pii(v, c));
        adj[v].push_back(pii(i, c));
    }

    dfs(1);
    for(int i = 1; i <= n; i++){
        if(dp[i] > a[i]){
            deleted[i] = true;
        }
    }

    int cont = 0;

    dfs(1, -1, cont);
    cout << n - cont << "\n";

    return 0;   
}
