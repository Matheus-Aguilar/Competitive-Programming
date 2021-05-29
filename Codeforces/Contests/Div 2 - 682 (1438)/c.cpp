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

const int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N;
vector<vector<int>> g, gr;
vector<int> order, comp;
vector<bool> vis, ans;

void init(int n){
    N = 2 * n;

    g.clear(), gr.clear(), order.clear();
    
    g.resize(N);
    gr.resize(N);
}

void addEdge(int u, bool notU, int v, bool notV){
    int p = 2 * u + notU;
    int q = 2 * v + notV;

    g[p^1].push_back(q);
    g[q^1].push_back(p);

    gr[q].push_back(p^1);
    gr[p].push_back(q^1);
}

void dfs1(int u){
    vis[u] = true;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(!vis[v])
            dfs1(v);
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
    
    vis.assign(N, false);
    for(int i = 0; i < N; i++){
        if(!vis[i])
            dfs1(i);
    }

    comp.assign(N, -1);
    for(int i = 0, j = 0; i < N; i++){
        int u = order[N - i - 1];
        if(comp[u] == -1)
            dfs2(u, j++);
    }
}

bool solve2SAT(){

    kosaraju();

    ans.resize(N/2);
    for(int i = 0; i < N; i += 2){
        if(comp[i] == comp[i + 1])
            return false;
        ans[i/2] = comp[i] > comp[i + 1];
    }

    return true;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        
        init(n * m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 4; k++){
                    
                    int i2 = i + moves[k][0];
                    int j2 = j + moves[k][1];

                    if(i2 >= 0 && j2 >= 0 && i2 < n && j2 < m){
                        if(a[i][j] == a[i2][j2]){
                            addEdge(i * m + j, false, i2 * m + j2, false);
                            addEdge(i * m + j, true, i2 * m + j2, true);
                        }
                        else if(a[i][j] == a[i2][j2] + 1){
                            addEdge(i * m + j, false, i2 * m + j2, true);
                        }
                    }
                }
            }
        }

        if(solve2SAT()){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << a[i][j] + ans[i * m + j] << " \n"[j==m-1];
                }
            }
        }
    }
    
    return 0;   
}
