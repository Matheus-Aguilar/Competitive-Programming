#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 1001000

using namespace std;

int n, p[MAXN], g[MAXN], cnt[MAXN], total = 0, ans[MAXN];
vector<int> adj[MAXN];

void dfs(int u){
    
    cnt[g[u]]++;

    if(cnt[g[u]] == 1)
        total++;

    ans[u] = total;

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v != p[u]){
            dfs(v);
        }
    }

    cnt[g[u]]--;

    if(cnt[g[u]] == 0)
        total--;
}

int main(){

    optimize;

    cin >> n;

    int s;

    for(int i = 1; i <= n; i++){
        cin >> p[i];
        if(p[i] == 0)
            s = i;
        else
            adj[p[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++){
        cin >> g[i];
    }

    dfs(s);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " \n"[i==n];
    }

    return 0;
}