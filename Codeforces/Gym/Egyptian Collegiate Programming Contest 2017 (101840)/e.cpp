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
#define MAXN 100100

using namespace std;

int fac[MAXN];

void sieve(ll n){
    
    ms(fac, -1);

    for(ll i = 2; i < n; i++){
        if(fac[i] == -1){
            for(ll j = i * i; j < n; j += i){
                fac[j] = i;
            }
            fac[i] = i;
        }
    }
}

int numFac(int x){
    
    int cont = 0;
    
    while(fac[x] != -1){
        cont++;
        x /= fac[x];
    }
    
    return cont;
}

void precalc(int u, int p, vector<vector<pii>> &adj, vector<int> &sz, vector<int> &heavy, vector<int> &sum){
    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i].first;

        if(v != p){
            sum[v] = sum[u] + adj[u][i].second;
            precalc(v, u, adj, sz, heavy, sum);
            sz[u] += sz[v];
            if(heavy[u] == -1 || sz[heavy[u]] < sz[v]) heavy[u] = v;
        }
    }
}

void solve(int u, int p, vector<vector<pii>> &adj, vector<int> &heavy, vector<vector<int>> &vec, vector<int> &sum, ll &ans){
    
    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i].first;

        if(v != p && v != heavy[u]){
            solve(v, u, adj, heavy, vec, sum, ans);
        }
    }

    ll cnt[3] = {0, 0, 0}, now[3];

    //Add heavy child nodes
    if(heavy[u] != -1){
        solve(heavy[u], u, adj, heavy, vec, sum, ans);
        vec[u].swap(vec[heavy[u]]);
    }

    //Count heavy child nodes
    for(int i = 0; i < vec[u].size(); i++){
        int v = vec[u][i];
        if(sum[v] - sum[u] >= 3) continue;
        cnt[sum[v] - sum[u]]++;
    }

    //Add light child nodes
    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i].first;

        if(v != p && v != heavy[u]){

            now[0] = now[1] = now[2] = 0;
            
            for(int j = 0; j < vec[v].size(); j++){
                vec[u].push_back(vec[v][j]);
                if(sum[vec[v][j]] - sum[u] >= 3) continue;
                now[sum[vec[v][j]] - sum[u]]++;
            }

            ans += cnt[0] * now[2];
            ans += cnt[2] * now[0];
            ans += cnt[1] * now[1];

            cnt[0] += now[0];
            cnt[1] += now[1];
            cnt[2] += now[2];
        }
    }

    //Add myself
    vec[u].push_back(u);
    ans += cnt[2];
}

int main(){
    optimize;

    sieve(100010);

    ifstream in("evaluations.in");

    int T;

    in >> T;
    
    for(int t = 1; t <= T; t++){

        int n;
        in >> n;

        ll ans = 0;
        vector<vector<pii>> adj(n);
        vector<vector<int>> vec(n);
        vector<int> sum(n, 0);
        vector<int> sz(n, 1);
        vector<int> heavy(n, -1);

        for(int i = 0; i < n - 1; i++){
            
            int u, v, c;
            in >> u >> v >> c;

            adj[u - 1].emplace_back(v - 1, numFac(c));
            adj[v - 1].emplace_back(u - 1, numFac(c));
        }

        precalc(0, -1, adj, sz, heavy, sum);
        solve(0, -1, adj, heavy, vec, sum, ans);

        cout << "Case " << t << ": " << ans << "\n";
    }

    return 0;   
}
