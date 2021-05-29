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

vector<vector<int>> adj;
vector<vector<int>> edges;
vector<bool> visit;
vector<int> ans;

int main(){
    optimize;
    
    int n;
    cin >> n;

    adj.resize(n);
    ans.resize(n - 1, -1);
    edges.resize(n);
    visit.assign(n, false);

    bool hasDeg3 = false;
    
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[u].push_back(i);
        edges[v].push_back(i);
        
        if(!hasDeg3 && edges[u].size() >= 3){
            for(int i = 0; i < 3; i++)
                ans[edges[u][i]] = i;
            hasDeg3 = true;
        }
        else if(!hasDeg3 && edges[v].size() >= 3){
            for(int i = 0; i < 3; i++)
                ans[edges[v][i]] = i;
            hasDeg3 = true;
        }
    }

    if(!hasDeg3)
        iota(all(ans), 0);
    else{
        int j = 3;
        for(int i = 0; i < n; i++){
            if(ans[i] == -1){
                ans[i] = j++;
            }
        }
    }

    for(int i:ans) cout << i << "\n";

    return 0;
}
