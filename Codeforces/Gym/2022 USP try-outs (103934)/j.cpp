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
#define MAXN 200020

using namespace std;

int n, m, q;
vector<pii> adj[MAXN], adj2[MAXN];
 
/*Tarjan*/
int low[MAXN], num[MAXN], cont = 0;
 
void tarjan(int u, int p = -1){
	
	low[u] = num[u] = cont++;
 
	for(int i = 0; i < adj[u].size(); i++){
		
		int v = adj[u][i].first;
		int w = adj[u][i].second;
 
		if(num[v] == -1){
			tarjan(v, u);
			if(low[v] > num[u]){
				adj2[u].emplace_back(v, w);
			} else {
				adj2[u].emplace_back(v, INF);	
			}
			low[u] = min(low[u], low[v]);
		} else if(v != p) {
			low[u] = min(low[u], num[v]);
		}
	}
}
 
/* SegTree */
int seg[4 * MAXN], lazy[4 * MAXN], val[MAXN];

void build(int t, int tl, int tr){
	if(tl == tr){
		seg[t] = val[tl];
		lazy[t] = -1;
    } else {
		int tm = tl + (tr - tl) / 2;
 
		build(2 * t, tl, tm);
		build(2 * t + 1, tm + 1, tr);
 
		seg[t] = min(seg[2 * t], seg[2 * t + 1]);
		lazy[t] = -1;
    }
}
 
void push(int t, int tl, int tr){
	
	if(lazy[t] == -1)
		return;
 
	if(tl != tr){
		lazy[2 * t] = lazy[t];
		lazy[2 * t + 1] = lazy[t];
	}
	
	seg[t] = lazy[t];
	lazy[t] = -1;
}

void update(int t, int tl, int tr, int l, int r, int v){

	push(t, tl, tr);

    if(l > tr || r < tl){
		return;
	} else if(l <= tl && r >= tr){
		lazy[t] = v;
		push(t, tl, tr);
    } else {
		int tm = tl + (tr - tl) / 2;
		update(2 * t, tl, tm, l, r, v);
		update(2 * t + 1, tm + 1, tr, l, r, v);
		seg[t] = min(seg[2 * t], seg[2 * t + 1]);
    }
}
 
/*HLD*/
int cur = 0, par[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], e[MAXN], sz[MAXN];

void dfs(int u){
	
	sz[u] = 1;
	heavy[u] = -1;
	int max_sz = 0;
 
	for(int i = 0; i < adj2[u].size(); i++){
		
		int v = adj2[u][i].first;
		int w = adj2[u][i].second;
		
		if(v != par[u]){
			par[v] = u;
			depth[v] = depth[u] + 1;
			
			e[v] = w;
			
			dfs(v);
			sz[u] += sz[v];

			if(heavy[u] == -1 || sz[v] > sz[heavy[u]]){
				heavy[u] = v;
			}
		}
	}
}
 
void decompose(int u, int h){
	
	head[u] = h;
	pos[u] = cur++;
 
	val[pos[u]] = e[u];
 
	if(heavy[u] != -1)
		decompose(heavy[u], h);
	
	for(int i = 0; i < adj2[u].size(); i++){
		int v = adj2[u][i].first;
		if(v != par[u] && v != heavy[u]){
			decompose(v, v);
		}
	}
}
 
void init(int root){
 
	par[root] = -1;
	depth[root] = 0;
    e[root] = INF;
 
	dfs(root);
	decompose(root, root);
 
	build(1, 0, n - 1);
}
 
void updateHLD(int u, int v){
	
	while(head[u] != head[v]){
		if(depth[head[u]] > depth[head[v]])
			swap(u, v);
		update(1, 0, n - 1, pos[head[v]], pos[v], INF);
		v = par[head[v]];
	}
 
	if(depth[u] > depth[v])
		swap(u, v);
	
	update(1, 0, n - 1, pos[u] + 1, pos[v], INF);
}
 
int main() {
 
	optimize;
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].emplace_back(v - 1, w);
		adj[v - 1].emplace_back(u - 1, w);
	}
 
	ms(num, -1);
	tarjan(0);	
 
	init(0);
 
	int q;
	cin >> q;
 
	int best = 0;
 
	for(int i = 0; i < q; i++){
		int u, v, w;
		cin >> u >> v >> w;
 
		u--;
		v--;
		
		updateHLD(u, v);
		int ans = seg[1];
		
		if(ans == INF)
			cout << -1 << "\n";
		else
			cout << ans << "\n";
 
	}

	return 0;
}