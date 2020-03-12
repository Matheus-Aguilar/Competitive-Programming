#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAXN 100100
#define ll long long

using namespace std;

ll cont;
ll n, m;
ll order[MAXN];
ll deg[MAXN];
bool isUnlocked[MAXN];
vector<vector<ll>> adj;

void search(int n){
    for(int i:adj[n]){
        --deg[i];
        if(!deg[i] && isUnlocked[i]){
            ++cont;
            search(i);
        }
    }
}

void solve(ll index){
    if(index >= n) return;
    ll n = order[index];
    
    isUnlocked[n] = true;

    if(!deg[n]){
        ++cont;
        search(n);
    }
    
    cout << cont << "\n";
    solve(index + 1);
}

int main(){
    optimize;
    while(cin >> n >> m){
        
        memset(isUnlocked, 0, sizeof(bool) * n);
        memset(deg, 0, sizeof(ll) * n);
        adj.resize(n);
        
        while(m--){
            ll a, b;
            cin >> a >> b;
            --a; --b;
            adj[a].push_back(b);
            deg[b]++;
        }
        
        for(ll i = 0; i < n; i++){
            cin >> order[i];
            --order[i];
        }

        cont = 0;
        solve(0);

        adj.clear();
    }
}