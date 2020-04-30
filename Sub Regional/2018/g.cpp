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
#define MAXN 2100
#define MAXM 88010

using namespace std;

struct Edge{
    int u, v, c;
};

int p, r, c, ans, tMax, total;
vector<Edge> e;
vector<int> gs;
vector<int> rf;

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

void init() {
   memset(first, -1, sizeof(first));
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

bool check(int t){
    
    init();
    memset(cap, 0, sizeof(cap));

    for(int i = 0; i < r; i++)
        add(p + r, i, rf[i]);
    for(int i = 0; i < p; i++)
        add(r + i, p + r + 1, gs[i]);
    for(int i = 0; i < c; i++){
        if(e[i].c <= t)
            add(e[i].v, r + e[i].u, INF);
    }

    int max_flow = dinic(p + r, p + r + 1);

    return max_flow == total;
}

int bin_search(int l, int r){
    while(l < r){
        int m = l + (r - l)/2;
        if(check(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    optimize;
    
    cin >> p >> r >> c;

    gs.resize(p);
    rf.resize(r);
    e.resize(c);

    tMax = 0;

    for(int i = 0; i < p; i++) 
        cin >> gs[i];
    for(int i = 0; i < r; i++) 
        cin >> rf[i];
    for(int i = 0; i < c; i++){
        cin >> e[i].u >> e[i].v >> e[i].c;
        e[i].u--, e[i].v--;
        tMax = max(tMax, e[i].c);
    }

    total = accumulate(all(gs), 0);
    ans = bin_search(1, tMax + 1);

    cout << (ans <= tMax ? ans : -1) << "\n";

    return 0;   
}
