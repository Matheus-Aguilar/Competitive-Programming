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

int n, m;

set<int> odd, even;
vector<set<int>> adj;
vector<int> g;

int main(){
    optimize;
    
    cin >> n >> m;

    adj.resize(n);
    g.assign(n, 0);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u - 1].insert(v-1);
        g[u - 1]++;

        swap(u, v);

        adj[u - 1].insert(v-1);
        g[u - 1]++;
    }

    for(int i = 0; i < n; i++){
        if(g[i] % 2 != 0)
            odd.insert(i);
        else
            even.insert(i);
    }

    vector<tuple<int, int, int>> ans;

    while(!odd.empty() || !even.empty()){
        
        int u = -1, v = -1, w = -1;

        if(!odd.empty())
            u = *odd.begin();
        else
            u = *even.begin();

        for(int aux : adj[u]){
            if(adj[aux].size() > 1){
                v = aux;
                break;
            }
        }

        for(int aux : adj[v]){
            if(g[aux] % 2 != 0 && aux != u){
                w = aux;
                break;
            }
        }

        if(w == -1){
            for(int aux : adj[v]){
                if(aux != u){
                    w = aux;
                    break;
                }
            }
        }

        ans.emplace_back(u+1,v+1,w+1);

        g[u]--;
        g[w]--;
        g[v] -=2;

        adj[u].erase(v);
        adj[v].erase(u);
        adj[v].erase(w);
        adj[w].erase(v);

        if(g[u] % 2 == 0){
            odd.erase(u);
            if(g[u] != 0){
                even.insert(u);
            }
        }
        else {
            even.erase(u);
        }

        if(g[w] % 2 == 0){
            odd.erase(w);
            if(g[w] != 0){
                even.insert(w);
            }
        }
        else {
            even.erase(w);
        }

        if(g[v] == 0){
            even.erase(v);
        }
    }

    cout << ans.size() << "\n";

    for(int i = 0; i < ans.size(); i++){
        cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << "\n";
    }

    return 0;   
}
