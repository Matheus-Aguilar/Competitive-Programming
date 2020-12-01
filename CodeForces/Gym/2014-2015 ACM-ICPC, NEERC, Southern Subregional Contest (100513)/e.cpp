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
#define fi first
#define se second

#define MAXN 403000
#define MAXM 1800000

using namespace std;

/*
 * ITA - Dinic's Algorithm - O(EV^2)
 */

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], from[MAXM], nxt[MAXM];

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, from[ned] = u, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, from[ned] = v, cap[ned] = 0;
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

bool checkEdge(int m1, int r1, int m2, int r2){
    
    int sm1 = (m1 > r1) + (m2 > r2);
    int sr1 = (m1 <= r1) + (m2 <= r2);

    int sm2 = (m1 + m2) > (r1 + r2);
    int sr2 = (m1 + m2) <= (r1 + r2);

    return (sm1 == sm2) && (sr1 > sr2);
}

int main(){
    optimize;

    int n, diff = 0;
    cin >> n;

    vector<pii> v(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> v[i].fi >> v[i].se;

        if(v[i].fi > v[i].se) 
            diff++;
        else
            diff--;
    }
    
    init();
    
    //Fonte
    for(int i = 1; i <= n; i++)
        add(0, i, 1);

    //Sorvedouro
    for(int i = 1; i <= n; i++)
        add(i + n, 2 * n + 1, 1);

    if(diff <= 0){
        add(2 * n + 1, 2 * n + 2, -diff + 1);
    }
    else{
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 2; i <= n; i += 2){
        if(checkEdge(v[i].fi, v[i].se, v[i - 1].fi, v[i - 1].se)){
            add(i, i + n - 1, 1);
        }
        if(i < n && checkEdge(v[i].fi, v[i].se, v[i + 1].fi, v[i + 1].se)){
            add(i, i + n + 1, 1);
        }
    }

    int maxflow = dinic(0, 2 * n + 2);

    if(maxflow == -diff + 1){
        
        cout << maxflow << "\n";

        for(int i = 1; i < ned; i += 2){
            if(from[i] > 0 && from[i] <= 2 * n && to[i] > 0 && to[i] <= 2 * n && cap[i] > 0){
                cout << to[i] << " " << from[i] - n << "\n";
            }
        }
    }
    else
        cout << -1 << "\n";

    return 0;   
}
