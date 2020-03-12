#include<bits/stdc++.h>
#define mod 1000000007
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

void toposort(vector<vector<int>> &adj, vector<int> &deg, vector<int> &sorted){
    queue<int>q;
    for(int i = 0; i < deg.size(); i++)
        if(!deg[i]) q.push(i);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        sorted.push_back(now);
        for(int i:adj[now]){
            deg[i]--;
            if(!deg[i]) q.push(i);
        }
    }
}

int main(){
    optimize;
    int n, l;
    cin >> n >> l;
    vector<vector<int>> adj(n);
    vector<int>deg(n, 0);
    vector<int>msg(n, 0);
    vector<bool>reachable(n, false);

    for(int i = 0; i < l; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int u;
            cin >> u;
            adj[i].push_back(u - 1);
            deg[u - 1]++;
        }
    }

    vector<int> sorted;

    toposort(adj, deg, sorted);

    msg[0] = 1;
    reachable[0] = true;
    for(int i = 0; i < n; i++){
        for(int j:adj[sorted[i]]){
            msg[j] += msg[sorted[i]] % mod;
            msg[j] %= mod;
            reachable[j] = reachable[j] || reachable[sorted[i]];
        }
    }

    int a, b;
    a = b = 0;

    for(int i = l; i < n; i++){
        a += msg[i];
        a %= mod;
        b += reachable[i] ? 1 : 0;
    }

    cout << a << " " << b << "\n";

    return 0;
}