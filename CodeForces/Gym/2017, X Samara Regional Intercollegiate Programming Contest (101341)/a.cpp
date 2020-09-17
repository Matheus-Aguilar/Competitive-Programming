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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string v[MAXN];

void solve(){

    multiset<pii> sP;
    multiset<tuple<int,int,int>> sN;

    for(int i=0;i<N;i++){
        int aux = 0, menor = INF, abre = 0;

        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == '(') {
                aux++;
                abre++;
            }
            else{
                aux--;
                if(abre) abre--;
            }

            menor = min(menor, aux);
        }

        if(menor >= 0){
            sP.insert(pii(-menor, i));
        }
        else{
            sN.insert(make_tuple(-abre, -aux, i));
        }
    } 

    string aux;
    vector<int> ans(N,0);

    int cnt = 0;
    
    for(auto i : sP){

        aux += v[ i.se ];
        ans[cnt++] = i.se +1; 
    }

    for(auto i : sN){

        aux += v[ get<2>(i) ];
        ans[cnt++] = get<2>(i) +1; 
    }

    cnt = 0;

    cout << aux << endl;

    for(int i=0;i<aux.size();i++){
        if(aux[i] == '(')   cnt++;
        else                cnt--;

        if(cnt < 0){
            cout << "NO\n";
            return;
        }
    }

    if(cnt){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    //for(int i=0;i<N;i++) cout << ans[i] << " \n"[i==N-1];
}

int main(){

	optimize;
	
	cin >> N;
		
    for(int i=0;i<N;i++) cin >> v[i];

	solve();

	return 0;
}