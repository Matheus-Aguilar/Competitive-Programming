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
#define MAXN 10010

using namespace std;

/*
 * Kosaraju SCC O(n)
 */

vector<int> adjList[MAXN], revAdjList[MAXN], ts;
bool vis[MAXN];
int comp[MAXN], numSCC;

void revdfs(int u) {
    vis[u] = true;
    for(int i = 0, v; i < (int)revAdjList[u].size(); i++) {
    	v = revAdjList[u][i];
        if(!vis[v]) revdfs(v);
    }
    ts.push_back(u);
}

void dfs(int u) {
    vis[u] = true; comp[u] = numSCC;
    for(int i = 0, v; i < (int)adjList[u].size(); i++) {
    	v = adjList[u][i];
        if(!vis[v]) dfs(v);
    }
}

void kosaraju(int n) {
	memset(&vis, false, sizeof vis);
    for(int i = 0; i < n; i++)  {
        if(!vis[i]) revdfs(i);
    }
    memset(&vis, false, sizeof vis);
    numSCC = 0;
    for(int i = n-1; i >= 0; i--) {
        if(!vis[ts[i]]) {
            dfs(ts[i]);
            numSCC++;
        }
    }
}


int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
        revAdjList[v - 1].push_back(u - 1);
    }

    kosaraju(n);

    if(numSCC == 1){
        cout << 0 << "\n";
    } else {
        int head = numSCC, leaf = numSCC;
        vector<int> in(numSCC, 0), out(numSCC, 0);
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < adjList[i].size(); j++){
                
                int v = adjList[i][j];
                
                int ci = comp[i];
                int cv = comp[v];

                if(ci == cv)
                    continue;

                if(out[ci] == 0)
                    leaf--;
                if(in[cv] == 0)
                    head--;

                out[ci]++;
                in[cv]++;
            }
        }

        cout << max(head, leaf) << "\n";
    }
    
    return 0;   
}
