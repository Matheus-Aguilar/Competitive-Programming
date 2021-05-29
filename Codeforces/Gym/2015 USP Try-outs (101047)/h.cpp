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

#define MAXN 103000
#define MAXM 900000

/*
 * Dinic's Algorithm - O(EV^2)
 */

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			int df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}

void dfs(int u, vector<vector<int>> &adj, vector<int> &c){
    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i];
 
        if(c[v] == -1){
            c[v] = !c[u]; 
            dfs(v, adj, c);
        }
    }
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        init();

        vector<vector<int>> adj(n + 1);
        vector<int> c(n + 1, -1);

        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        c[1] = 0;
        dfs(1, adj, c);

        for(int i = 1; i <= n; i++){

            if(c[i])
                add(i, n + 1, 1);
            else
                add(0, i, 1);

            for(int j = 0; j < adj[i].size(); j++){
                int v = adj[i][j];
                
                if(!c[i]) 
                    add(i, v, 1);
                else
                    add(v, i, 1);
            }
        }

        int maxMatch = dinic(0, n + 1);

        cout << n - maxMatch << "\n";
    }
    
    return 0;   
}
