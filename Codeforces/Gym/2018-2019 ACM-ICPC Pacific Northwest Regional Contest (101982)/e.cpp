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
using namespace std;

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

int main(){
    optimize;

    int n, m, c;
    cin >> m >> n >> c;

    int sx, sy;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<int> cost(c);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            char ch;
            cin >> ch;

            if(ch == 'B'){
                sx = i;
                sy = j;
                grid[i][j] = -1;
                continue;
            }

            if(ch == '.'){
                grid[i][j] = -1;
                continue;
            }

            grid[i][j] = (ch - 'a');
        }
    }

    for(int i = 0; i < c; i++){
        cin >> cost[i];
    }

    init();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            int u = i * m + j;
            
            for(int x = -1; x <= 1; x += 2){
                
                if(i + x < 0 || i + x >= n) continue;

                int v = (i + x) * m + j;
                
                add(2 * u + 1, 2 * v, INF);
            }
            
            for(int y = -1; y <= 1; y += 2){

                if(j + y < 0 || j + y >= m) continue;

                int v = i * m + j + y;

                add(2 * u + 1, 2 * v, INF);
            }

            if(grid[i][j] != -1)
                add(2 * u, 2 * u + 1, cost[grid[i][j]]);
            else
                add(2 * u, 2 * u + 1, INF);
        }   
    }

    int source = 2 * n * m, sink = 2 * n * m + 1, bank = sx * m + sy;

    for(int i = 0; i < n; i++){

        int u = i * m;
        int v = i * m + (m - 1); 

        add(2 * u + 1, sink, INF);
        add(2 * v + 1, sink, INF);
    }

    for(int j = 0; j < m; j++){
        
        int u = j;
        int v = (n - 1) * m + j; 

        add(2 * u + 1, sink, INF);
        add(2 * v + 1, sink, INF);
    }

    add(source, 2 * bank, INF);

    int maxflow = dinic(source, sink);

    if(maxflow >= INF)
        cout << -1 << "\n";
    else
        cout << maxflow << "\n";

    return 0;   
}
