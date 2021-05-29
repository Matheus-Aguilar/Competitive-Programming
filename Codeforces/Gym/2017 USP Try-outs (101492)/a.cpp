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

int n, m, k;

vector<vector<int>> adj;
vector<int> f;

void dfs(int u, int c){
    
    f[u] = c + 1;

    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i];

        if(f[v] == -1){
            dfs(v, (c + 1) % k);
        }
    }
}

int main(){
    optimize;

    cin >> n >> m >> k;

    if(k == 1){

        if(m != 0){
            cout << -1 << "\n";
        }
        else{
            for(int i = 0; i < n; i++)
                cout << 1 << "\n";
        }

        return 0;
    }

    adj.resize(n);
    f.assign(n, -1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    for(int i = 0; i < n; i++){
        if(f[i] == -1){
            dfs(i, 0);
        }
    }

    for(int i = 0; i < n; i++){
        cout << f[i] << "\n";
    }
    
    return 0;   
}
