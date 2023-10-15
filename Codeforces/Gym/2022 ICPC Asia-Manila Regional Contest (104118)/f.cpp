#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;

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
#define MAXN 200400

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
ll W[MAXN], WT = 0;

struct cmp1{
    bool operator()(const pii &a, const pii &b) const{
        if(a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

struct cmp2{
    bool operator()(const pii &a, const pii &b) const{
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};

set<pii, cmp1> small;
set<pii, cmp2> big;
set<int> idx;

void add(int i){
    small.emplace(W[i], i);
    big.emplace(W[i], i);
    idx.insert(i);
    WT += W[i];
}

void rem(int i){
    small.erase(make_pair(W[i], i));
    big.erase(make_pair(W[i], i));
    idx.erase(i);
    WT -= W[i];
}

bool isHegem(){
    if(big.empty())
        return false;
    ll best = big.begin()->first;
    return (WT - best < best);
}

void collapse(int i){
    ll val = W[i] / 2;
    
    auto it = idx.find(i);
    vector<pii> change;

    if(it != idx.begin()){
        auto it2 = it;
        it2--;
        change.emplace_back(W[*it2] + val, *it2);
    }

    it++;

    if(it != idx.end()){
        change.emplace_back(W[*it] + val, *it);
    }

    for(auto [v, i] : change){
        rem(i);
        W[i] = v;
        add(i);
    }
    
    rem(i);
}

void solve() {
	cin >> N;

    for(int i = 0; i< N; ++i) {
        cin >> W[i];
        add(i);
    }

    for(int i = 0; i < N; i++){
        if(!isHegem()){
            cout << big.begin()->second + 1 << " " << big.begin()->first << "\n";
            collapse(big.begin()->second);
        } else {
            cout << small.begin()->second + 1 << " " << small.begin()->first << "\n";
            collapse(small.begin()->second);
        }
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