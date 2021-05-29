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

struct Edge{
    int u, v;
    Edge(int _u = -1, int _v = -1, int _c = -1) : u(_u), v(_v){ 
        if(u > v) 
            swap(u, v);
    }
    bool operator<(const Edge &e){ 
        if(v != e.v)
            return v < e.v;
        return u < e.u;
    }
};

struct UnionFind{
    vector<int> par;
    UnionFind(int n){
        par.resize(n);
        iota(all(par), 0);
    }
    void merge(int a, int b){
        par[find(a)] = find(b);
    }
    int find(int a){
        if(par[a] != a)
            par[a] = find(par[a]);
        return par[a];
    }
};

vector<Edge> e;

int kruskal(int n){
    vector<int> deg(n, 0);
    UnionFind uf(n);
    sort(all(e));

    for(int i = 0; i < e.size(); i++){
        if(uf.find(e[i].u) != uf.find(e[i].v)){
            deg[e[i].u]++, deg[e[i].v]++;
            uf.merge(e[i].u, e[i].v);
        }
    }

    return *max_element(all(deg));
}

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    e.resize(m);

    while(m--){
        int x, y;
        cin >> x >> y;
        e[m] = Edge(x - 1, y - 1);
    }

    cout << kruskal(n) << "\n";

    return 0;   
}
