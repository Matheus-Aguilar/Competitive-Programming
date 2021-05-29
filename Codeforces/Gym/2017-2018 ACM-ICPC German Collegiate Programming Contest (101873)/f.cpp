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
#define MAXN 103000
#define MAXM 900000

using namespace std;

/*
 * Dinic's Algorithm - O(EV^2)
 */

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

vector<pii> buffer;

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

int dfs(int u, int f, int t, bool buf) {

    if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			int df = dfs(v, min(f, cap[e]), t, buf);
			if (df > 0) {
				
                cap[e] -= df;
				cap[e^1] += df;

                if(buf){
                    buffer.emplace_back(e, df);
                }

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

int dinic(int s, int t, bool buf) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t, buf)) result += f;
	}
	return result;
}

void undo(){
    for(pii e : buffer){
        cap[e.first] += e.second;
        cap[e.first ^ 1] -= e.second;
    }
    buffer.clear();
}

int main(){
    optimize;

    init();

    int m, n, k;
    vector<int> begEdges, endEdges;

    cin >> m >> n >> k;

    //Fonte
    for(int i = 1; i <= n; i++){
        add(0, i, 1);
        begEdges.push_back(ned - 2);
    }

    //Intermediarios
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        add(y, x + n, 1);
    }

    //Sorvedouro
    for(int i = 1; i <= m; i++){
        add(i + n, n + m + 1, 1);
        endEdges.push_back(ned - 2);
    }

    int best = dinic(0, n + m + 1, false);
    
    for(int e : endEdges){
        cap[e] += 2;

        dinic(0, n + m + 1, true);

        int flow = 0;

        for(int e2 : begEdges){
            flow += (cap[e2 ^ 1] > 0);
        }

        best = max(best, flow);

        undo();
        cap[e] -= 2;
    }

    cout << best << "\n";

    return 0;   
}
