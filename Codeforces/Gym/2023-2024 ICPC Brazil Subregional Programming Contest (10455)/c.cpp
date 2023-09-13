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

int n, last[MAXN], pos[MAXN], val[MAXN], ans[MAXN];
vector<int> adj[MAXN], seq;

void dfs(int u, int p = -1){

    pos[u] = lower_bound(all(seq), val[u]) - seq.begin();

    if(pos[u] == seq.size()){
        seq.push_back(val[u]);
        last[u] = -1;
    }
    else {
        last[u] = seq[pos[u]];
        seq[pos[u]] = val[u];
    }

    ans[u] = seq.size();

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v != p)
            dfs(v, u);
    }

    if(last[u] == -1)
        seq.pop_back();
    else {
        seq[pos[u]] = last[u];
    }
}

int main(){
    optimize;
    
    cin >> n;

    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        adj[i].push_back(p - 1);
        adj[p - 1].push_back(i);
    }

    for(int i = 0; i < n; i++)
        cin >> val[i];

    dfs(0);

    for(int i = 1; i < n; i++)
        cout << ans[i] << " \n"[i+1==n];

    return 0;   
}
