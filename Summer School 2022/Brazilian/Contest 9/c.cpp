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

bool solve(string &s, vector<vector<int>> &adj, int b, int e, int n){
    
    vector<bool> vis(n, false);
    
    queue<int> q;
    q.push(b);

    vis[b] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(s[v] != '#' && !vis[v]){
                q.push(v);
                vis[v] = true;
            }
        }
    }

    return !vis[e];
}

int main(){
    optimize;

    ifstream in("portals.in");

    int t;

    in >> t;

    while(t--){
        int n;
        in >> n;

        string s;
        in >> s;

        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++){
            adj[i - 1].push_back(i);
            adj[i].push_back(i - 1);
        }

        for(int i = 0; i < n - 1; i++){
            adj[i + 1].push_back(i);
            adj[i].push_back(i + 1);
        }

        int b, e, last = -1;

        for(int i = 0; i < n; i++){
            if(s[i] == 'o'){
                if(last != -1){
                    adj[last].push_back(i);
                    adj[i].push_back(last);
                }
                last = i;
            }
            else if(s[i] == 's')
                b = i;
            else if(s[i] == 'e')
                e = i;
        }

        vector<pair<int, string>> g;
        g.emplace_back(0, s);

        for(int i = 0; i < n; i++){
            if(s[i] == 's' || s[i] == 'e'){
                if(i > 0 && s[i - 1] == '.'){
                    s[i - 1] = '#';
                    g.emplace_back(1, s);
                    s[i - 1] = '.';
                }
                if(i < n - 1 && s[i + 1] == '.'){
                    s[i + 1] = '#';
                    g.emplace_back(1, s);
                    s[i + 1] = '.';
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(s[i] == 's' || s[i] == 'e'){
                if(i > 0 && i < n - 1 && s[i - 1] == '.' && s[i + 1] == '.'){
                    s[i - 1] = '#';
                    s[i + 1] = '#';
                    g.emplace_back(2, s);
                    s[i - 1] = '.';
                    s[i + 1] = '.';
                }
            }
        }

        int ans = -1;

        for(int i = 0; i < g.size(); i++){
            if(solve(g[i].second, adj, b, e, n)){
                ans = g[i].first;
                break;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
