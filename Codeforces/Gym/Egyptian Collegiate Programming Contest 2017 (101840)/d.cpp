#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

vector<int> primes;
vector<int> fac;

void sieve(int n){

    fac.assign(n, -1);

    for(ll i = 2; i < n; i++){
        if(fac[i] == -1){
            for(ll j = i * i; j < n; j += i){
                fac[j] = i;
            }
            fac[i] = i;
            primes.push_back(i);
        }
    }
}

struct UnionFind{

    vector<int> p;

    UnionFind(int n){
        p.resize(n);
        iota(all(p), 0);
    }

    int find(int a){
        if(p[a] == a) return a;
        p[a] = find(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        int pa = find(a), pb = find(b);
        p[pa] = pb;
    }

    bool sameSet(int a, int b){
        return find(a) == find(b);
    }
};

struct Edge{
    int u, v, c;
    Edge(int _u = 0, int _v = 0, int _c = 0) : u(_u), v(_v), c(_c) {}
    bool operator<(const Edge &e){
        if(c != e.c) return c > e.c;
        if(u != e.u) return u < e.u;
        return v < e.v;
    }
};

ll kruskal(vector<Edge> &e, int n){
    
    sort(all(e));

    int cont = 0;
    ll sum = 0;

    UnionFind uf(n);

    for(int i = 0; i < e.size(); i++){
        if(!uf.sameSet(e[i].u, e[i].v)){
            sum += e[i].c;
            cont++;
            uf.merge(e[i].u, e[i].v);
        }
    }

    return sum + (n - 1) - cont;
}

int main(){
    optimize;

    sieve(100100);

    ifstream in("dream.in");

    int T;
    in >> T;

    for(int t = 1; t <= T; t++){

        int n;
        in >> n;

        ll ans = 0;
        vector<int> v(n), r(primes.size(), -1);
        vector<Edge> e;

        for(int i = 0; i < n; i++)
            in >> v[i];
        
        for(int i = 0; i < n; i++){
            
            int val = v[i];

            while(fac[val] != -1){
                
                int p = fac[val];
                int pos = lower_bound(all(primes), p) - primes.begin();
                
                val /= p;

                if(r[pos] == -1 || v[r[pos]] < v[i]){
                    r[pos] = i;
                }
            }
        }

        for(int i = 0; i < n; i++){
            
            int val = v[i];

            while(fac[val] != -1){
                
                int p = fac[val];
                int pos = lower_bound(all(primes), p) - primes.begin();
                
                val /= p;

                if(r[pos] == i) continue;
            
                e.emplace_back(i, r[pos], __gcd(v[r[pos]], v[i]));
            }
        }

        cout << "Case " << t << ": " << kruskal(e, n) << "\n";
    }
    
    return 0;   
}
