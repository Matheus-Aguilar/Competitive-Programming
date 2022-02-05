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
#define MAXN 550

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
char A[MAXN][MAXN];

void solve() {

	cin >> N >> M;
	
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 0;

    if(N == 1) {
        for(int j = 1; j < M - 1; j++) if(A[0][j] == '.') ans++;
        cout << ans << endl;
        return;
    }
    if(N == 2) {
        for(int j = 1; j < M - 1; j++) if(A[0][j] == '.' && A[1][j] == '.') ans++;
        cout << ans << endl;
        return;
    }
    if(M == 1) {
        for(int i = 1; i < N - 1; i++) if(A[i][0] == '.') ans++;
        cout << ans << endl;
        return;
    }
    if(M == 2) {
        for(int i = 1; i < N - 1; i++) if(A[i][0] == '.' && A[i][1] == '.') ans++;
        cout << ans << endl;
        return;
    }

    for(int i = 1; i < N - 1; i++) {
        for(int j = 1; j < M - 1; j++) {
            if(A[i][j] == '.') ans++;
        }
    }

    int aux = 0;
    for(int i = 0; i < N; i++) if(A[i][0] != '.' || A[i][M-1] != '.') aux++;
    for(int j = 0; j < M; j++) if(A[0][j] != '.' || A[N-1][j] != '.') aux++;

    cout << ans + (aux == 0) << endl;

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