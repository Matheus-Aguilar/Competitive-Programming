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

using namespace std;

int red = 0, black = 0;
ll ans = 0;
vector<vector<int>> adj;

void dfs(int u, int p, bool isRed){
    if(isRed){
        ans += max(black - 1, 0);
        red++;
    }
    else{
        ans += max(red - 1, 0);
        black++;
    }

    for(int v:adj[u]){
        if(v != p){
            dfs(v, u, !isRed);
        }
    }
}

int main(){
    optimize;

    int n;
    cin >> n;
    adj.resize(n);
    while(--n){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1, false);
    cout << ans << "\n";

    return 0;   
}
