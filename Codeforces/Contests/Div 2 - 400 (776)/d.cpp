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
#define fi first
#define se second

using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<int>> gr;
vector<bool> visit;
vector<int> comp;
vector<int> value;
vector<int> order;
vector<pii> prop;

void build(){
    g.resize(2 * n);
    gr.resize(2 * n);
    visit.assign(2 * n, false);
    comp.assign(2 * n, -1);
    value.resize(n);

    for(int i = 0; i < (int)prop.size(); i++){
        g[prop[i].fi ^ 1].push_back(prop[i].se);
        g[prop[i].se ^ 1].push_back(prop[i].fi);
        gr[prop[i].se].push_back(prop[i].fi ^ 1);
        gr[prop[i].fi].push_back(prop[i].se ^ 1);
    }
}

void dfs(int u){
    visit[u] = true;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(!visit[v])
            dfs(v);
    }
    order.push_back(u);
}

void dfs2(int u, int c){
    comp[u] = c;
    for(int i = 0; i < gr[u].size(); i++){
        int v = gr[u][i];
        if(comp[v] == -1)
            dfs2(v, c);
    }
}

void kosaraju(){
    for(int i = 0; i < 2 * n; i++){
        if(!visit[i])
            dfs(i);
    }
    for(int i = 0, j = 0; i < 2 * n; i++){
        int u = order[2 * n - i - 1];
        if(comp[u] == -1)
            dfs2(u, j++);
    }
}

bool solve2SAT(){
    build();
    kosaraju();
    for(int i = 0; i < 2 * n; i += 2){
        if(comp[i] == comp[i ^ 1])
            return false;
        value[i/2] = (comp[i] > comp[i ^ 1]);
    }
    return true;
}

int main(){
    optimize;

    cin >> m >> n;

    vector<int> door(m);
    vector<vector<int>> switches(m);

    for(int i = 0; i < m; i++)
        cin >> door[i];
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            switches[x - 1].push_back(i);
        }
    }
    for(int i = 0; i < m; i++){
        if(door[i]){
            prop.push_back(pii(2*switches[i][0], 2*switches[i][1] + 1));
            prop.push_back(pii(2*switches[i][1], 2*switches[i][0] + 1));
        }
        else{
            prop.push_back(pii(2*switches[i][0], 2*switches[i][1]));
            prop.push_back(pii(2*switches[i][0] + 1, 2*switches[i][1] + 1));
        }
    }

    cout << (solve2SAT() ? "YES" : "NO") << "\n";
    
    return 0;   
}
