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

    vector<vector<int>> adj(n, vector<int>(m, -1));
    vector<vector<ll>> dist(n, vector<ll>(n, 0));
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++){
        
        int q;
        cin >> q;

        while(q--){
            int c, g;
            cin >> c >> g;
            adj[i][c - 1] = g;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            
            bool inf = true;

            for(int k = 0; k < m; k++){
                if(adj[i][k] != -1 && adj[j][k] != -1){
                    dist[i][j] += (adj[i][k] - adj[j][k]) * (adj[i][k] - adj[j][k]);
                    inf = false;
                }
            }

            if(inf) dist[i][j] = INFLL;
            dist[j][i] = dist[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        
        int close = !i;
        
        for(int j = 0; j < n; j++){
            if(i != j && dist[i][close] > dist[i][j]){
                close = j;
            }
        }

        if(dist[i][close] == INFLL)
            continue;

        for(int j = 0; j < m; j++){
            if(adj[i][j] == -1 && adj[close][j] != -1){
                if(ans[i] == -1 || adj[close][ans[i] - 1] < adj[close][j]){
                    ans[i] = j + 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << "\n";
    
    return 0;   
}
