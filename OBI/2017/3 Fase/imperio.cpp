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
vector<int> adj[MAXN];
int height[MAXN];
int subtree[MAXN];

void dfs(int u, int p = -1){
    subtree[u] = 1;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v != p){
            height[v] = height[u] + 1;
            dfs(v, u);
            subtree[u] += subtree[v];
        }
    }
}

int main(){
    optimize;
    
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    dfs(0);

    int best = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            int u = i, v = adj[i][j];
            if(height[u] > height[v])
                swap(u, v);
            best = min(best, abs(n - 2 * subtree[i]));
        }
    }

    cout << best << "\n";

    return 0;   
}
