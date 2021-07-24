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

const ll p = 1000000007LL;

int n, k;
vector<vector<int>> adj;
vector<ll> fat;

ll fastExpo(ll x, ll y){
    
    ll r = 1;

    while(y > 0){
        if(y & 1)
            r = (r * x) mod;
        x = (x * x) mod;
        y >>= 1;
    }

    return r;
}

ll comb(int a, int b){
    ll num = fat[a];
    ll div = (fat[b] * fat[a - b]) mod;
    return (num * fastExpo(div, p - 2)) mod;
}

ll solve(int u, ll c, bool root = false){
    
    ll ans = c;

    for(int i = 0; i < adj[u].size(); i++){
        
        int v = adj[u][i];

        if(root)
            ans = (ans * solve(v, c - 1)) mod;
        else
            ans = (ans * solve(v, c)) mod;
    }

    return ans;
}

int main(){
    optimize;

    cin >> n >> k;

    adj.resize(n);
    fat.assign(k + 1, 1LL);

    for(int i = 1; i <= k; i++){
        fat[i] = (fat[i - 1] * i) mod;
    }

    for(int i = 1; i < n; i++){
        int v;
        cin >> v;
        adj[v].push_back(i);
    }

    ll ans = 0;

    bool sum = true;

    for(int i = k; i >= 1; i--){
        
        ll aux = (solve(0, i, true) * comb(k, i)) mod;
    
        if(sum) 
            ans = (ans + aux) mod;
        else 
            ans = (ans - aux + p) mod;
    
        sum = !sum;
    }

    cout << ans << "\n";
    
    return 0;   
}