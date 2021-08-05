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
    vector<int> p;

    UnionFind(int n){
        p.resize(n);
        iota(all(p), 0);
    }

    int find(int x){
        if(p[x] == x)
            return x;
        p[x] = find(p[x]);
        return p[x];
    }

    void merge(int x, int y){
        int px = find(x);
        int py = find(y);
        p[px] = py;
    }

    bool sameSet(int x, int y){
        int px = find(x);
        int py = find(y);
        return px == py;
    }
};

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    vector<pii> e(m);
    vector<int> p(m);
    vector<int> ans(m);

    for(int i = 0; i < m; i++)
        cin >> e[i].first >> e[i].second;
    
    for(int i = 0; i < m; i++)
        cin >> p[i];
    
    int cont = n;
    ans[m - 1] = cont;

    for(int i = m - 1; i > 0; i--){
        
        int u = e[p[i] - 1].first - 1, v = e[p[i] - 1].second - 1;
        
        if(!uf.sameSet(u, v))
            cont--;
        uf.merge(u, v);

        ans[i - 1] = cont;
    }

    for(int i = 0; i < m; i++)
        cout << ans[i] << "\n";

    return 0;   
}
