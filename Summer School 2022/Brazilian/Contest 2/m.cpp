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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
#define MAXN 110

vector<int> adjU[MAXN];
int pairU[MAXN], pairV[MAXN];
bool vis[MAXN];
int m, n;

bool dfs(int u) {
    vis[u] = true;
    if (u == 0) return true;
    for (int i = 0; i < (int)adjU[u].size(); i++) {
        int v = adjU[u][i];
        if (!vis[pairV[v]] && dfs(pairV[v])) {
            pairV[v] = u; pairU[u] = v;
            return true;
        }
    }
    return false;
}

int kuhn() {
    memset(&pairU, 0, sizeof pairU);
    memset(&pairV, 0, sizeof pairV);
    int result = 0;
    for (int u = 1; u <= m; u++) {
        memset(&vis, false, sizeof vis);
        if (pairU[u]==0 && dfs(u)) result++;
    }
    return result;
}

int A[MAXN][MAXN], v[MAXN][MAXN];
pii moves[] = { {0,-1}, {0,+1}, {-1,0}, {+1,0} };
vector<pii> edge;
int cnt = 0;

bool validPos(int i, int j) {
    if(i < 0 || j < 0 || i >= N || j >= N) return false;
    return true;
}

void constroiEdge() {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j] == 1) cnt++;
            
            for(int k = 0; k < 4; k++) {
            
                int i2 = i + moves[k].fi;
                int j2 = j + moves[k].se;

                if(validPos(i2, j2) && A[i2][j2] == A[i][j] + 1) {
                    cerr << pii(i,j) << " " << pii(i2,j2) << endl;
                    //cerr << "add: " << pii(i * N + j + 1, i2 * N + j2 + 1) << endl;
                    adjU[i * N + j + 1].pb((i2 * N + j2 + 1));
                } 
            }
        }
    } 

}

void solve() {

	cin >> N;

    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> A[i][j];

    constroiEdge();

    m = N;
    n = N;
    
    cout << N*N << " " << kuhn() << " " << cnt << endl;
    bool ok = (N*N - kuhn() == cnt);
    
    cout << (ok ? "YES\n":"NO\n");

    for(int i = 0; i < N + 1; i++) {
        adjU[i].clear();
    }

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
