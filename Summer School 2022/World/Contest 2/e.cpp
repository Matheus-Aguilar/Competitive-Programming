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
ll A[MAXN];

struct Fila{
    vector<ll> fila, mdc;

    Fila(){
        mdc.pb(0);
    }

    void push(ll c){
        fila.pb(c);
        mdc.pb(__gcd(mdc.back(), c));
    }

    ll pop(){
        ll c = fila.back();
        fila.pop_back();
        mdc.pop_back();

        return c;
    }

    ll get() {
        return mdc.back();
    }

    bool empty() {
        return fila.empty();
    }
};

ll getMDC(Fila & f1, Fila & f2){
    return __gcd(f1.get(), f2.get());
}

void inverte(Fila & f1, Fila & f2){
    
    while(!f1.empty()) {
        ll c = f1.pop();
        f2.push(c);
    }
}

void solve() {

	cin >> N;

    Fila f1, f2;
    
    for(int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    ll ptr = 0, ptr2 = 0;

    for( ; ptr < N; ptr++){
        
        f1.push(A[ptr2++]);

        ans = max(ans, (ptr2 - ptr) * getMDC(f1, f2));
        
        if(ptr2 < N) {
            ll proxValue = __gcd(getMDC(f1, f2), A[ptr2]) * (ptr2 + 1 - ptr);
            ll actualValue   = getMDC(f1, f2) * (ptr2 - ptr);

            while(ptr2 < N && proxValue >= actualValue){
                f1.push(A[ptr2++]);
                ans = max(ans, (ptr2 - ptr) * getMDC(f1, f2));
            }
        }

        if(f2.empty()) inverte(f1, f2);
        
        f2.pop();
        ptr++;
    }

    cout << ans << endl;
    
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
