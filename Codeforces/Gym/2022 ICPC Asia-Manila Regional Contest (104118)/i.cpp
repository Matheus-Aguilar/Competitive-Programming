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

int c[MAXN], id[MAXN], raw = 0;
vector<int> adj[MAXN];
ll qnt[MAXN][20], total[20], sum[20];

void toposort(){
	
	queue<int> q;

	for(int i = 0; i < M; i++){
		if(c[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			c[v]--;

			for(int j = 0; j < raw; j++){
				qnt[v][j] += qnt[u][j];
				qnt[v][j] = min(qnt[v][j], (ll) INF);
			}
			
			if(c[v] == 0){
				q.push(v);
			}
		}
	}
}

void solve() {
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		cin >> c[i];

		if(c[i] == 0){
			id[i] = raw++;
			cin >> total[id[i]];
		} else {
			for(int j = 0; j < c[i]; j++){
				int v;
				cin >> v;
				adj[v - 1].push_back(i);
			}
		}
	}

	for(int i = 0; i < M; i++){
		if(c[i] == 0){
			qnt[i][id[i]] = 1;
		}
	}

	toposort();

	int ans = 0;

	for(int i = 0; i < (1 << N); i++){
		
		bool ok = true;
		ms(sum, 0);
		
		for(int j = 0; j < N && ok; j++){
			if(i & (1 << j)){
				for(int k = 0; k < raw; k++){
					sum[k] += qnt[j][k];
				}		
			}
		}

		for(int k = 0; k < raw && ok; k++)
			ok = sum[k] <= total[k];

		if(ok)
			ans = max(ans, __builtin_popcount(i));
	}

	cout << ans << "\n";
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