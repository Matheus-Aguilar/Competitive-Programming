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

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> t(n);
    vector<pii> p(n);
    vector<int> mex(n, 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        cin >> t[i];
        p[i].first = t[i];
        p[i].second = i;
    }

    bool ans = true;
    for(int i = 0; i < n && ans; i++)
        for(int j = 0; j < adj[i].size() && ans; j++)
            ans &= (t[i] != t[adj[i][j]]);
    
    if(!ans){
        cout << -1 << "\n";
    }
    else{
        sort(all(p));
        for(int i = 0; i < n; i++){
            int u = p[i].second;
            if(mex[u] != t[u]){
                ans = false;
                break;
            }
            for(int j = 0; j < adj[u].size(); j++){
                int v = adj[u][j];
                if(mex[v] == t[u])
                    mex[v] = t[u] + 1;
            }
        }

        if(!ans)
            cout << -1 << "\n";
        else{
            for(int i = 0; i < n; i++)
                cout << p[i].second + 1 << " ";
            cout << "\n";
        }
    }

    return 0;   
}
