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
#define MAXN 100010
#define MAXL 32

using namespace std;

int n, m, age[MAXN], bit[MAXN], dp[MAXN][MAXL], ans[MAXN];
vector<int> adj[MAXN], part[MAXN];

int query(int x){
    int sum = 0;
    for(; x > 0; x -= -x&x)
        sum += bit[x];
    return sum;
}

void update(int x, int v){
    for(; x < MAXN; x += -x&x)
        bit[x] += v;
}

void dfs(int u, int p = -1){
    
    for(int i = 0; i < adj[u].size(); i++){
    
        int v = adj[u][i];
        
        if(v != p){
            dp[v][0] = u;
            dfs(v, u);
        }
    }
}

void precalc(int u){
    
    ms(dp, -1);
    
    dfs(u);

    for(int j = 1; j < MAXL; j++){
        for(int i = 0; i < n; i++){
            if(dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

int binLift(int u, int r){
    
    for(int i = MAXL - 1; i >= 0; i--){
        if(dp[u][i] != -1 && age[dp[u][i]] <= r){
            u = dp[u][i];
        }
    }
    
    return u;
}

void solve(int u, int p = -1){
    
    for(int i = 0; i < part[u].size(); i++)
        update(part[u][i], 1);
    
    for(int i = 0; i < adj[u].size(); i++){
    
        int v = adj[u][i];
        
        if(v != p){
            dp[v][0] = u;
            solve(v, u);
        }
    }

    ans[u] = query(age[u]);

    for(int i = 0; i < part[u].size(); i++)
        update(part[u][i], -1);
}

int main(){
    optimize;

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        age[i] = a;

        if(i == 0) continue;

        adj[i].push_back(b - 1);
        adj[b - 1].push_back(i);
    }

    precalc(0);

    for(int i = 0; i < m; i++){
        int o, l, r, p;
        cin >> o >> l >> r;

        p = binLift(o - 1, r);
        part[p].push_back(l);
    }

    solve(0);

    for(int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];

    return 0;   
}
