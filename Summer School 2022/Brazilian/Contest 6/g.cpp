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
int A[MAXN], B[MAXN], C[MAXN], F[MAXN][2];

void solve() {

    cin >> N;
    
    for(int i = 1; i <= N; i++) cin >> A[i];

    B[0]        = INF;
    C[N + 1]    = INF;

    for(int i = 1; i <= N; i++) B[i] = min(B[i - 1], A[i]);
    for(int i = N; i ; i--) C[i] = min(C[i + 1], A[i]);

    int cnt = 0;

    for(int i = 1; i <= N; i++) {
        if(B[i] >= A[i])  F[i][0] = 1;
        else if(B[i] + C[i] >= A[i]) F[i][0] = 2;  
        else F[i][0] = 3;
    }

    for(int i = N; i ; i--) {
        if(C[i] >= A[i])  F[i][1] = 1;
        else if(B[i] + C[i] >= A[i]) F[i][1] = 2;  
        else F[i][1] = 3;
    }

    int ptr = 1, ptr2 = N;

    for(; ptr <= N; ptr++)  if(F[ptr][0] != 1) break;
    for(; ptr2; ptr2--)      if(F[ptr2][1] != 1) break;

    // for(int i = 1; i <= N; i++) cout << F[i][0] << " \n"[i==N];
    // for(int i = 1; i <= N; i++) cout << F[i][1] << " \n"[i==N]; 
    // cerr << pii(ptr, ptr2) << endl;

    for(int i = ptr; i <= ptr2; i++) {
        if(F[i][0] == 3) {
            cnt = 2;
            break;
        }
        else if(F[i][0] == 1) continue;
        else if(F[i][0] == 2 && F[i - 1][0] == 1) {
            cnt++;
        }
    }

    cout << ( (cnt <= 1) ? "YES\n" : "NO\n");
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