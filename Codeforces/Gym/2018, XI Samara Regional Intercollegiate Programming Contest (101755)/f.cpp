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
#define MAXN 1100

using namespace std;

int n;
int deg[MAXN];
vector<int> adj[MAXN];
vector<pii> edges;

void toposort(){

    vector<int> q;
    vector<int> aux;
    
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0)
            q.push_back(i);
    
    while(!q.empty()){
        for(int i = 0; i < q.size(); i++){    
            
            int u = q[i];
            
            for(int j = 0; j < adj[u].size(); j++){
                int v = adj[u][j];
                deg[v]--;
            }
        }
        for(int i = 0; i < q.size(); i++){    
            
            int u = q[i];
            
            for(int j = 0; j < adj[u].size(); j++){
                int v = adj[u][j];
                if(deg[v] == 0){
                    edges.emplace_back(u, v);
                    aux.push_back(v);
                }
            }
        }

        q = aux;
        aux.clear();
    }
}

int main(){
    optimize;
    
    cin >> n;

    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        while(k--){
            int j;
            cin >> j;
            adj[i].push_back(j);
            
            if(j == i){
                cout << "NO" << "\n";
                return 0;
            }
            
            deg[j]++;
        }
    }

    toposort();

    if(edges.size() == n - 1){
        cout << "YES" << "\n";
        for(int i = 0; i < n - 1; i++)
            cout << edges[i].first << " " << edges[i].second << "\n";
    }
    else
        cout << "NO" << "\n";

    return 0;   
}
