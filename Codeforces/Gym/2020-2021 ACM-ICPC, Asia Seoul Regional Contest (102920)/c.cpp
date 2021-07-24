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

int n, k, d[MAXN];
bool s[MAXN], c[MAXN];
vector<pii> adj[MAXN];

void solve(){
    
    queue<int> q;

    for(int i = 0; i < n; i++){
        
        if(d[i] == 1){
            q.push(i);
        }
        
        c[i] = true;
    }

    while(!q.empty()){
        
        int u = q.front();
        q.pop();

        if(!s[u]){
            for(int i = 0; i < adj[u].size(); i++){
                
                int v = adj[u][i].first;
                
                if(!c[v]) continue;
                
                d[v]--;
                
                if(d[v] == 1)
                    q.push(v);
            }

            c[u] = false;
        }
    }
}

int main(){
    optimize;

    cin >> n >> k;
    
    for(int i = 0; i < n - 1; i++){
        
        int u, v, w;
        cin >> u >> v >> w;
        
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);

        d[u - 1]++;
        d[v - 1]++;
    }

    for(int i = 0; i < k; i++){
        int u;
        cin >> u;
        s[u - 1] = true;
    }

    solve();

    int cont = 0;

    for(int i = 0; i < n; i++){
        if(c[i]){
            cont++;
        }
    }

    cout << cont << "\n";

    return 0;   
}
