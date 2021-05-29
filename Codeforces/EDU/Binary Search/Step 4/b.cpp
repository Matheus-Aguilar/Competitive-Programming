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

using namespace std;

int n, m;

int nxt[MAXN];
double dp[MAXN];
bool visit[MAXN];

vector<pii> adj[MAXN];

void dfs(int u, double m){
    
    visit[u] = true;

    if(dp[u] == INF){
        for(int i = 0; i < adj[u].size(); i++){
            
            int v = adj[u][i].first;
            double w = adj[u][i].second - m;

            if(!visit[v]){
                
                dfs(v, m);
                
                if(dp[v] + w < dp[u]){
                    dp[u] = dp[v] + w;
                    nxt[u] = v;
                }
            }
        }
    }

    visit[u] = false;
}

bool solve(double m){

    for(int i = 0; i < n; i++){
        dp[i] = INF;
        visit[i] = false;
        nxt[i] = -1;
    }
    
    dp[n - 1] = 0;

    dfs(0, m);

    return dp[0] <= 0;
}

double binSearch(double l, double r){
    
    double m;
    
    for(int i = 0; i < 150; i++){
        m = l + (r - l)/2;

        if(solve(m))
            r = m;
        else
            l = m;
    }

    return r;
}

int main(){
    optimize;
    
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].emplace_back(b - 1, c);
    }

    double best = binSearch(0, 110);

    solve(best);

    vector<int> sol;

    int u = 0;

    while(u != -1){
        sol.push_back(u);
        u = nxt[u];
    }

    cout << (int) sol.size() - 1 << "\n";
    
    for(int i = 0; i < sol.size(); i++)
        cout << sol[i] + 1 << " \n"[i==sol.size()-1];

    return 0;   
}
