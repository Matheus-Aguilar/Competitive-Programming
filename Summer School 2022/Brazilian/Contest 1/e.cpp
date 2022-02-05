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

pii moves[] = { {-2,-1}, {+2,-1}, {-2,+1}, {+2,+1}, {-1,-2}, {+1,-2}, {-1,+2}, {+1,+2} };

bool validPos(int x, int y) {
    if(x < 1 || x > 8 || y < 1 || y > 8) return false;
    return true;
}

struct Cavalo {
    int a,b;

    Cavalo() {}
    Cavalo(int _a, int _b) : a(_a), b(_b) {}

    vector<pii> getJogadas() {
        
        int c = a, d = b;
        vector<pii> possiveisJogadas;

        for(int i = 0; i < 8; i++) {
            c = a + moves[i].fi;
            d = b + moves[i].se;

            if(validPos(c,d)) possiveisJogadas.emplace_back(c,d);
        }

        return possiveisJogadas;
    }

    void joga() {
        vector<pii> possiveisJogadas = getJogadas();

        int pos = rng() % possiveisJogadas.size();

        a = possiveisJogadas[pos].fi;
        b = possiveisJogadas[pos].se;
    }   

};

Cavalo A,B;
int cnt = 0, lim = 1e6;
int pA, pB;

bool win(){
    if(A.a == B.a && A.b == B.b) return true;
    return false;    
}

int ax, ay, bx, by;

void solve() {
    int K = 100000, ca = 0, cb = 0;

    for(int k = 0; k < K; k++){
        A.a = ax, A.b = ay;
        B.a = bx, B.b = by;

        bool white = true;

        while(!win()){
            if(white) {
                A.joga();
            }
            else {
                B.joga();
            }
            white = !white;
        }

        if(white){
            cb++;
        } else {
            ca++;
        }
    }

    double diff = abs(ca - cb);
    diff /= K;

    if(diff < 1e-6){
        cout << "draw" << "\n";
    }
    else if(ca > cb) {
        cout << "white" << "\n";
    }
    else {
        cout << "black" << "\n";
    }
}

int main() {

	optimize;
	
    cin >> ax >> ay;
    cin >> bx >> by;

	solve();
    
	return 0;
}