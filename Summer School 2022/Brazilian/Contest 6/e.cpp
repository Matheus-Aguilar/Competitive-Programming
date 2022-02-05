#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

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
vector<vector<int>> adj;
vector<int> vis, path;
vector<char> resp, pathChar;
int ans;

pii bfs(int u) {

    queue<pii> fila;

    fila.push({0, u});
    pii last(0, u);

    vis[u] = true;

    while(!fila.empty()) {
        int t = fila.front().fi;
        int v = fila.front().se;

        fila.pop();

        for(auto i : adj[v]) {
            if(!vis[i]) {
                vis[i] = true;
                fila.push({t + 1, i});
                last = pii(t + 1, i);
            }        
        }
    }

    return last;
}

void bfs2(int u) {

    queue<pii> fila;

    fila.push({0, u});
    vis[u] = true;

    while(!fila.empty()) {
        int t = fila.front().fi;
        int v = fila.front().se;

        if(t >= pathChar.size()) {
            cout << "Impossible!\n";
            ans = -1;
            return;
        }

        resp[v] = pathChar[t];

        fila.pop();

        for(auto i : adj[v]) {
            if(!vis[i]) {
                vis[i] = true;
                fila.push({t + 1, i});
            }        
        }
    }
}

int dfs(int u, int p, int t) {
    
    if(u == t) {
        path.pb(u);
        return vis[u] = true;
    }

    int ans = 0;

    for(auto i : adj[u]){
        if(i != p){
            ans = max(ans, dfs(i, u, t));
        }
    }

    if(ans) path.pb(u);
    vis[u] = ans;

    return ans;
}

void f(int i) {
    
    for(int j = 0; j < 26; j++) {
        pathChar.push_back('A' + j);
    }

}

void solve() {

	cin >> N;

    adj.resize(N);
    resp.resize(N);

    for(int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;

        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    f(0);
    pii v[3];

    vis.assign(N, 0);
    v[0] = bfs(0);

    vis.assign(N, 0);
    v[1] = bfs(v[0].se);

    vis.assign(N, 0);
    dfs(v[0].se, -1, v[1].se);

    vis.assign(N, 0);
    bfs2(path[path.size() / 2]);

    if(ans == -1) return;

    for(int i = 0; i < N; i++) cout << resp[i] << " \n"[i == N - 1];
}

int main() {

	optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
