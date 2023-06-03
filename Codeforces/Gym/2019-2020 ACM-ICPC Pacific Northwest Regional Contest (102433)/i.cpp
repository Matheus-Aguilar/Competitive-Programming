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
#define MAXN 550

using namespace std;

int m = 0, n = 0, sn, c[MAXN], pairU[MAXN], pairV[MAXN], idx[MAXN];
bool vis[MAXN];
string s[MAXN];
vector<int> adj[MAXN], adjU[MAXN];

void getBipartite(int u, int col){
    
    c[u] = col;

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(c[v] == 0){
            getBipartite(v, (col == 1 ? 2 : 1));
        }
        assert(c[v] != c[u]);
    }
}

bool dfs(int u){

    vis[u] = true;
    
    if(u == 0) return true;
    
    for(int i = 0; i < adjU[u].size(); i++){
        
        int v = adjU[u][i];
        
        if(!vis[pairV[v]] && dfs(pairV[v])){
            pairV[v] = u;
            pairU[u] = v;
            return true;
        }
    }

    return false;
}

int kuhn(){
    ms(pairU, 0);
    ms(pairV, 0);

    int result = 0;

    for(int u = 1; u <= m; u++){
        ms(vis, false);
        if(pairU[u] == 0 && dfs(u))
            result++;
    }

    return result;
}

int main(){
    optimize;

    cin >> sn;

    for(int i = 1; i <= sn; i++)
        cin >> s[i];
    
    for(int i = 1; i <= sn; i++){
        for(int j = i + 1; j <= sn; j++){
            
            int cnt = 0;
            
            for(int k = 0; k < s[i].size() && cnt <= 2; k++){
                if(s[i][k] != s[j][k])
                    cnt++;
            }
            
            if(cnt == 2){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= sn; i++){
        if(c[i] == 0)
            getBipartite(i, 1);
    }

    for(int i = 1; i <= sn; i++){
        if(c[i] == 1){
            idx[i] = ++m;
        } else {
            idx[i] = ++n;
        }
    }

    for(int i = 1; i <= sn; i++){
        if(c[i] == 1){
            for(int j = 0; j < adj[i].size(); j++){
                int v = adj[i][j];
                adjU[idx[i]].push_back(idx[v]);
            }
        }
    }

    cout << sn - kuhn() << "\n";

    return 0;   
}
