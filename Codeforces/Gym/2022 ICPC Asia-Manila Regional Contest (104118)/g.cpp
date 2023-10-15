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
#define MAXN 800400

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int sz[MAXN], l[MAXN], r[MAXN];

vector<int> vals;
vector<pii> adds;

int seg[4 * MAXN], lazy[4 * MAXN];

void build(int p, int tl, int tr){
	if(tl == tr){
		seg[p] = 0;
	} else {
		
		int tm = tl + (tr - tl) / 2;
		int e = (p << 1);
		int d = (p << 1) | 1;

		build(e, tl, tm);
		build(d, tm + 1, tr);
	
		seg[p] = max(seg[e], seg[d]);
	}
}

void push(int p, int tl, int tr){
	if(lazy[p] == 0)
		return;
	
	int e = (p << 1);
	int d = (p << 1) | 1;

	seg[p] += lazy[p];

	if(tl != tr){
		lazy[e] += lazy[p];
		lazy[d] += lazy[p];
	}

	lazy[p] = 0;
}

int query(int p, int tl, int tr, int a, int b){
	push(p, tl, tr);

	if(a > tr || b < tl){
		return 0;
	}
	if(tl >= a && tr <= b){
		return seg[p];
	}

	int tm = tl + (tr - tl) / 2;
	int e = (p << 1);
	int d = (p << 1) | 1;

	return max(query(e, tl, tm, a, b), query(d, tm + 1, tr, a, b));
}

void update(int p, int tl, int tr, int a, int b, int x){
	
	push(p, tl, tr);

	if(a > tr || b < tl){
		return;
	}
	if(tl >= a && tr <= b){
		lazy[p] += x;
		push(p, tl, tr);
		return;
	}

	int tm = tl + (tr - tl) / 2;
	int e = (p << 1);
	int d = (p << 1) | 1;

	update(e, tl, tm, a, b, x);
	update(d, tm + 1, tr, a, b, x);

	seg[p] = max(seg[e], seg[d]);
}

int getPos(int x){
	return lower_bound(all(vals), x) - vals.begin();
}

void solve() {
	cin >> N >> K;

	for(int i = 0; i < N; i++){
		cin >> l[i] >> r[i];
		sz[i] = r[i] - l[i] + 1;
		l[i] %= K;
		r[i] %= K;
	}

	if(N == 1){
		cout << N << "\n";
		return;
	}

	for(int i = 0; i < N; i++){
		if(sz[i] >= K){
			adds.emplace_back(0, K - 1);
		} else if(l[i] <= r[i]){
			adds.emplace_back(l[i], r[i]);
		} else {
			adds.emplace_back(l[i], K - 1);
			adds.emplace_back(0, r[i]);
		}
	}

	for(int i = 0; i < adds.size(); i++){
		vals.push_back(adds[i].first);
		vals.push_back(adds[i].second);
	}

	vals.push_back(0);
	vals.push_back(K - 1);

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	build(1, 0, vals.size() - 1);

	for(int i = 0; i < adds.size(); i++){
		int pos1 = getPos(adds[i].first);
		int pos2 = getPos(adds[i].second);
		update(1, 0, vals.size() - 1, pos1, pos2, 1);
	}
	cout << query(1, 0, vals.size() - 1, getPos(0), getPos(K - 1)) << "\n";
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