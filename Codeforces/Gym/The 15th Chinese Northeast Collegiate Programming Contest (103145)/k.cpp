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

struct UnionFind{
    vector<int> p, sz;

    UnionFind(int n){
        p.resize(n);
        sz.assign(n, 1);
        iota(all(p), 0);
    }

    int find(int u){
        if(u == p[u])
            return u;
        p[u] = find(p[u]);
        return p[u];
    }

    int getSize(int u){
        int pu = find(u);
        return sz[pu];
    }

    void merge(int u, int v){
        
        if(sameSet(u, v)) return;
        
        int pu = find(u), pv = find(v);

        if(sz[pu] > sz[pv]) swap(pu, pv);

        sz[pv] += sz[pu];
        p[pu] = pv;
    }

    bool sameSet(int u, int v){
        return find(u) == find(v);
    }
};

struct Edge{
    int u, v, k;
    Edge() {}
    Edge(int _u, int _v, int _k) : u(_u), v(_v), k(_k) {}
    bool operator<(const Edge &e){
        if(k != e.k) return k < e.k;
        if(u != e.u) return u < e.u;
        return v < e.v;
    }
};

ll numPairs(ll x){
    return (x * (x - 1)) / 2;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, m, q;
        cin >> n >> m >> q;

        UnionFind uf(n);
        vector<ll> sum(m + 1, 0);
        vector<Edge> e(m);

        for(int i = 0; i < m; i++){
            cin >> e[i].u >> e[i].v >> e[i].k;
            e[i].u--;
            e[i].v--;
        }
        
        sort(all(e));

        for(int i = 1, j = m - 1; i <= m && j >= 0; i++, j--){
            
            sum[i] += sum[i - 1];
            
            if(!uf.sameSet(e[j].u, e[j].v)){
                sum[i] -= numPairs(uf.getSize(e[j].u));
                sum[i] -= numPairs(uf.getSize(e[j].v));
                
                uf.merge(e[j].u, e[j].v);

                sum[i] += numPairs(uf.getSize(e[j].u));
            }
        }

        while(q--){
            int p, pos;
            cin >> p;

            pos =  lower_bound(all(e), Edge(-1, -1, p)) - e.begin();
            cout << sum[m - pos] << "\n";
        }
    }
    
    return 0;   
}
