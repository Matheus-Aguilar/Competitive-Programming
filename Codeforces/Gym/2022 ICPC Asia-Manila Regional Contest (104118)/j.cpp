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
#define MAXN 200

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

string mat[200];

void connect(int i0, int j0, int i1, int j1) {
    for(int j=j0; j<=j1; ++j) {
        mat[i0][j] = '#';
    }
    for(int j=j1; j<=j0; ++j) {
        mat[i0][j] = '#';
    }
    for(int i=i0; i<=i1; ++i) {
        mat[i][j1] = '#';
    }
    for(int i=i1; i<=i0; ++i) {
        mat[i][j1] = '#';
    }
}

void solve() {
	cin >> N >> M;
    for(int i=0; i<N ;++i) cin >> mat[i];
    vector<pair<int,int>> pts;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(mat[i][j] == '#') {
                pts.emplace_back(i, j);
            }
        }
    }

    sort(all(pts));

    connect(pts[1].first, pts[1].second, pts[0].first, pts[0].second);
    connect(pts[1].first, pts[1].second, pts[2].first, pts[2].second);

    for(int i=0; i<N; ++i) {
        cout << mat[i] << endl;
    }
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