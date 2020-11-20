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

int n;
vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;

void init(){
    g.clear();
    gt.clear();
    used.clear();
    order.clear();
    comp.clear();

    g.resize(2 * n);
    gt.resize(2 * n);
}

void addEdge(int u, bool notU, int v, bool notV){
    
    int p = 2 * u + notU;
    int q = 2 * v + notV;

    //p v q = ~p -> q = ~q -> p
    g[p ^ 1].push_back(q);
    g[q ^ 1].push_back(p);

    //arestas reversas
    gt[q].push_back(p ^ 1);
    gt[p].push_back(q ^ 1);
}

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve2SAT() {
    used.assign(2 * n, false);
    for (int i = 0; i <  2* n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(2 * n, -1);
    for (int i = 0, j = 0; i < 2 * n; ++i) {
        int v = order[2 * n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    for (int i = 0; i < 2 * n; i += 2)
        if (comp[i] == comp[i + 1])
            return false;
    
    return true;
}

int main(){
    optimize;

    int l, c, m;

    while(cin >> l >> c >> m){
        
        n = l + c;
        init();

        while(m--){
            int l0, c0, l1, c1;
            cin >> l0 >> c0 >> l1 >> c1;

            l0--, l1--, c0--, c1--;

            c0 += l;
            c1 += l;

            if(l0 == l1 && c0 == c1)
                continue;
            else if(l0 == l1){
                addEdge(l0, c0 < c1, l0, c0 < c1);
            }
            else if(c0 == c1){
                addEdge(c0, l0 < l1, c0, l0 < l1);
            }
            else{
                addEdge(l0, c0 < c1, l1, c0 < c1);
                addEdge(c0, l0 < l1, c1, l0 < l1);
                addEdge(l0, c0 < c1, c0, l0 < l1);
                addEdge(l1, c0 < c1, c1, l0 < l1);
            }
        }

        cout << (solve2SAT() ? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
