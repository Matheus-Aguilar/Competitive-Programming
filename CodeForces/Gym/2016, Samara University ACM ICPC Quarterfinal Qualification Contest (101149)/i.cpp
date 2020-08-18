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

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    vector<bool> ans(n, true);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    int minDeg = min_element(all(deg)) - deg.begin();
    
    ans[minDeg]= false;
    for(int i = 0; i < adj[minDeg].size(); i++)
        ans[adj[minDeg][i]]= false;

    for(int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];
    
    return 0;   
}
