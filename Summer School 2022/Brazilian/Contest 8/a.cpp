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

#define MAXN 2000200
#define MAXL 25

int st[2*MAXN][MAXL];
vector<vector<int>> adj;

struct LCA{
    vector<int> first,altura,euler,log;
    vector<bool> vis;
    int N,K;
    
    LCA(const vector<vector<int>> &adj , int root = 0){
        N = adj.size();
        K = log2(N)+1;
        first.resize(N);
        altura.resize(N);
        log.assign(2*N+1,0);
        euler.reserve(2*N);
        vis.assign(N,false);
        
        dfs(adj,root,0);

        build(euler.size());    
    }

    void dfs(const vector<vector<int>> &adj , int u,int h = 0){
        vis[u] = true;
        altura[u] = h;
        first[u] = euler.size();
        euler.push_back(u);
        
        for(auto i : adj[u]){
            if(!vis[i]){
                dfs(adj,i,h+1);
                euler.push_back(u);
            }
        }
    }

    void build(int n){
        memset(st,0,sizeof(st));

        for(int i=0;i<n;i++){
            st[i][0] = euler[i];
        }

        for(int j=1;j<=K;j++){
            for(int i=0;i + (1<<j) <= n;i++){
                int l = st[i][j-1];
                int r = st[i + (1<<(j-1))][j-1];
                st[i][j] =  altura [l] < altura[r] ? l : r;
            }
        }

        for(int i=2;i<=n;i++){
            log[i] = log[i/2] + 1;
        }
    }

    int query(int u, int v){
        int L = first[u];
        int R = first[v];

        if(L>R) swap(L,R);
        
        int j = log[R-L+1];

        int l = st[L][j];
        int r = st[R-(1<<j) + 1 ][j];
        return altura[l] < altura[r] ? l:r;
    }

    int getAlt(int u){
        return altura[u];
    }

    int dist(int u, int v){
        return getAlt(u) + getAlt(v) - 2*getAlt( query(u,v));
    }
};

int h, w, b[1100][1100][4];

void buildTree(){
    
    adj.resize(h * w);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!b[i][j][0] && i < h - 1)
                adj[i * w + j].push_back((i + 1) * w + j);
            if(!b[i][j][1] && i > 0)
                adj[i * w + j].push_back((i - 1) * w + j);
            if(!b[i][j][2] && j > 0)
                adj[i * w + j].push_back(i * w + j - 1);
            if(!b[i][j][3] && j < w - 1)
                adj[i * w + j].push_back(i * w + j + 1);
        }
    }
}

int main(){
    //optimize;

    cin >> h >> w;
    cin.ignore();

    for(int i = 0; i <= h; i++){
        
        string s;
        getline(cin, s);
        
        for(int j = 0; j < 2 * w + 1; j++){
            
            char c = s[j];

            //cout << "C: " << c << "---" << endl;

            int k = j / 2;

            if(c == '_'){
                if(i > 0)
                    b[i - 1][k][0] = true; 
                if(i < h)
                    b[i][k][1] = true;
            }
            else if(c == '|'){
                if(k < w)
                    b[i - 1][k][2] = true;
                if(k > 0)
                    b[i - 1][k - 1][3] = true;
            }
        }
    }
    
    int m;
    cin >> m;

    vector<int> x(m), y(m);

    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    buildTree();

    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         int k = i * w + j;

    //         cout << i << " " << j << ": ";

    //         for(int x = 0; x < adj[k].size(); x++){
    //             int v = adj[k][x];

    //             cout << "(" << v / w << ", " << v % w << ") "; 
    //         }
    //         cout << "\n";
    //     }
    // }
    
    LCA lca(adj);

    ll sum = 0;

    for(int i = 1; i < m; i++){
        sum += lca.dist(x[i - 1] * w + y[i - 1], x[i] * w + y[i]);
    }

    cout << sum << "\n";

    return 0;   
}
