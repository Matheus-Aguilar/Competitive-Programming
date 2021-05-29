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
#define MAXN 200100

using namespace std;

struct Node{
    ll v, cont[6];
    Node(){
        v = 1;
        ms(cont, 0);
    }
};

Node t[4 * MAXN];

int primes[6] = {2, 3, 5, 7, 11, 13};

int n, start[MAXN], subtreeSize[MAXN];
ll val[MAXN], cont[MAXN][6];
vector<int> adj[MAXN], euler;

void getFactors(ll arr[], ll value){
    
    int i = 0;

    while(value > 1){
        if(value % primes[i] == 0){
            value /= primes[i];
            arr[i]++;
        }
        else{
            i++;
        }
    }
}

void dfs(int u, int p = -1){
    
    subtreeSize[u] = 1;
    start[u] = euler.size();
    euler.push_back(u);

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];

        if(v != p){
            dfs(v, u);
            subtreeSize[u] += subtreeSize[v];
        }
    }
}

void combine(Node &a, Node &b, Node &c){
    c.v = (a.v * b.v) mod;
    for(int i = 0; i < 6; i++)
        c.cont[i] = a.cont[i] + b.cont[i];
}

void build(int node, int tl, int tr){
    if(tl == tr){
        t[node].v = val[euler[tl]];
        for(int i = 0; i < 6; i++)
            t[node].cont[i] = cont[euler[tl]][i];
    }
    else{
        int tm = tl + (tr - tl)/2;
        build(2 * node, tl, tm);
        build(2 * node + 1, tm + 1, tr);
        combine(t[2 * node], t[2 * node + 1], t[node]);
    }
}

Node query(int node, int tl, int tr, int l, int r){
    if(l > r)
        return Node();
    else if(tl == l && tr == r)
        return t[node];
    else{
        int tm = tl + (tr - tl)/2;
        
        Node left, right, result;
        
        left = query(2 * node, tl, tm, l, min(tm, r));
        right = query(2 * node + 1, tm + 1, tr, max(tm + 1, l), r);
        
        combine(left, right, result);
        
        return result;
    }
}

void update(int node, int tl, int tr, int p, ll v){
    if(tl == tr){

        ll fac[6] = {0};
        getFactors(fac, v);

        t[node].v = (t[node].v * v) mod;
        
        for(int i = 0; i < 6; i++)
            t[node].cont[i] += fac[i];
    }
    else{
        int tm = tl + (tr - tl)/2;
        
        if(p <= tm)
            update(2 * node, tl, tm, p, v);
        else
            update(2 * node + 1, tm + 1, tr, p, v);
        
        combine(t[2 * node], t[2 * node + 1], t[node]);
    }
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        cin >> val[i];
        getFactors(cont[i], val[i]);
    }

    dfs(0);
    build(1, 0, euler.size() - 1);

    int q;
    cin >> q;

    while(q--){
        string op;
        int u;

        cin >> op >> u;

        if(op == "RAND"){
            Node ans;
            ans = query(1, 0, euler.size() - 1, start[u], start[u] + subtreeSize[u] - 1);
            ll prod = 1LL;

            for(int i = 0; i < 6; i++)
                prod = (prod * (ans.cont[i] + 1)) mod;

            cout << ans.v << " " << prod << "\n";
        }
        else{
            ll x;
            cin >> x;
            update(1, 0, euler.size() - 1, start[u], x);
        }
    }
    
    return 0;   
}
