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

int n, cont = 0;
vector<int> h;
vector<bool> visit;
vector<vector<int>> adj, level;
vector<string> mat;

void dfs(int u){
    
    cont++;
    
    visit[u] = true;
    level[h[u]].push_back(u);
    
    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i];

        if(!visit[v]){
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}

int main(){
    optimize;

    cin >> n;

    h.assign(n, 0);
    adj.resize(n);
    level.resize(n);
    mat.resize(n);
    visit.assign(n, false);

    for(int i = 0; i < n; i++){
        
        cin >> mat[i];

        for(int j = 0; j < n; j++){
            if(mat[i][j] == '1')
                adj[i].push_back(j);
        }
    }

    dfs(0);

    if(cont != n)
        cout << "impossible" << "\n";
    else{
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < level[i].size(); j++){
                cout << level[i][j] << " \n"[i==0];
            }
        }
    }
    
    return 0;   
}
