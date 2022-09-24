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

const ll limit = 31622778;
vector<bool> prime;
vector<int> p;
int pos = 0;

void crivo(){
    prime.assign(limit, true);

    prime[0] = prime[1] = false;

    for(ll i = 2; i < limit; i++){
        if(prime[i]){
            for(ll j = i * i; j < limit; j += i){
                prime[j] = false;
            }
            p.push_back(i);
            pos++;
        }
    }
}

int main(){
    optimize;

    crivo();

    //cout << pos << "\n";

    int n, m, k;
    cin >> m >> n >> k;

    vector<ll> val(n);
    vector<vector<int>> adj(n + m);
    vector<ll> ans(m);

    for(int i = 0; i < n; i++)
        cin >> val[i];

    for(int i = 0; i < k; i++){
        int u, v, d;
        cin >> u >> v >> d;

        --u, --v;

        adj[u + n].push_back(v);
        adj[v].push_back(u + n);
    }

    int j = 0;

    for(int i = 0; i < m; i++){
        int u = i + n;
        
        while(j < pos && val[adj[u][0]] > 1 && val[adj[u][0]] % p[j] != 0){
            ++j;
        }

        for(int v : adj[u]){
            while(j < pos && val[v] % p[j] == 0){
                val[v] /= p[j];
            }
            if(val[v] != 1)
                ans[i] = val[v];
        }

        if(j < pos)
            ans[i] = p[j];

        ++j;
    }

    for(int i = 0; i < m; i++)
        cout << ans[i] << " \n"[i==m-1];
    
    return 0;   
}
