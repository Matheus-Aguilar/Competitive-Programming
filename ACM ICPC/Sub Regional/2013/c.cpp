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

void floyd(vector<vector<bool>> &adj, int n){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] = (adj[i][j] | (adj[i][k] & adj[k][j]));   
}

int main(){
    optimize;
    
    int n, m, i;
    while(cin >> n >> m >> i){
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        vector<int> ages(n);
        vector<int> vtok(n);
        vector<int> ktov(n);
        iota(all(vtok), 0);
        iota(all(ktov), 0);

        for(int i = 0; i < n; i++)
            cin >> ages[i];
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u][v] = true;
        }
        floyd(adj, n);

        while(i--){
            char op;
            cin >> op;
            if(op == 'T'){
                int u, v;
                cin >> u >> v;
                swap(ktov[u - 1], ktov[v - 1]);
                vtok[ktov[u - 1]] = u - 1, vtok[ktov[v - 1]] = v - 1;
            }
            else{
                int u, ans = INF;
                cin >> u;
                for(int i = 0; i < n; i++){
                    if(adj[i][ktov[u - 1]])
                        ans = min(ans, ages[vtok[i]]);
                }
                if(ans == INF)
                    cout << '*' << "\n";
                else
                    cout << ans << "\n";
            }
        }
    }

    return 0;   
}
