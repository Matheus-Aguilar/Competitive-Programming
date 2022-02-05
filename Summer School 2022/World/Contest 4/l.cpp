#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

vector<vector<pii>> adj;
ll F[MAXN], Q[MAXN], C[MAXN], D[MAXN];
ll sumEnt;

// F - quantidade de entregas para mim
// Q - Quantidade de entregas para mim e meus filhos
// C - Custo de mim e meus filhos
// D - Resposta enraizando a árvore em mim

void bfs(int u, int p) {

	ll q = 0, c = 0;

	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].fi;
		ll w = adj[u][i].se;

		if(p != v) {
			bfs(v, u);

			q += Q[v];
			c += Q[v] * w * 2LL + C[v]; 
		}
	}

	q += F[u];

	Q[u] = q;
	C[u] = c;
}

void bfs2(int u, int p, ll w) {

	if(p != -1) {
		ll ans = 0;

		ans = C[u] + (sumEnt - Q[u]) * 2LL * w + D[p] - C[u] - 2LL * w * Q[u]; 
		//ans = (sumEnt - Q[u]) * 2 * w + D[p] - 2 * w * Q[u]; 
		//ans = (sumEnt - Q[u]) * 2 * w - 2 * w * Q[u] + D[p]; 
		// ans = 2 * w * ((sumEnt - Q[u]) - Q[u]) + D[p];
		//ans = 2LL * w * (sumEnt - 2LL * Q[u]) + D[p];
		
		D[u] = ans;
	}

	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].fi;
		ll w = adj[u][i].se;

		if(p != v) {
			bfs2(v, u, w);
		}
	}
}

void solve() {

	cin >> N;

	adj.resize(N);

	for(int i = 0, u, v, w; i < N - 1; i++) {
		cin >> u >> v >> w;

		u--, v--;

		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}	

	cin >> M;

	sumEnt = 0;

	for(int i = 0, u, v; i < M; i++) {
		cin >> u >> v;

		u--;
		F[u] = v;
		sumEnt += v;
	}

	bfs(0, -1);

	D[0] = C[0];

	bfs2(0, -1, -1);

	vector<int> ans;
	ll bestValor = INFLL;

	for(int i = 0; i < N; i++) {
		ll aux = D[i];
		if(aux <= bestValor) {
			if(aux < bestValor) {
				bestValor = aux;
				ans.clear();
			}
			ans.push_back(i);
		}
	}
	
	cout << bestValor << "\n";
	for(int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " \n"[i == ans.size() - 1];

	for(int i = 0; i < N; i++) adj[i].clear();
}

int main() {

	optimize;
	
	T = 1;
	
	cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
