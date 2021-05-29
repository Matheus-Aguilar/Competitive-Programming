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

int n, m, n1, n2, n3;
vector<vector<int>> adj;
vector<vector<vector<int>>> part;
vector<int> c;
vector<vector<int>> dp;

void setColors(vector<int> &r, vector<int> &b){
    for(int i = 0; i < r.size(); i++){
        --n2;
        c[r[i]] = 2;
    }
    for(int i = 0; i < b.size(); i++){
        if(n1 > 0){
            --n1;
            c[b[i]] = 1;
        }
        else{
            --n3;
            c[b[i]] = 3;
        }
    }
}

bool solveDp(int i, int j){
    if(i == part.size())
        return j == 0;
    if(j < 0)
        return false;
    if(dp[i][j] == -1){
        dp[i][j] = false;
        if(solveDp(i + 1, j - part[i][0].size())){
            dp[i][j] = true;
            setColors(part[i][0], part[i][1]);
        }
        if(!dp[i][j] && solveDp(i + 1, j - part[i][1].size())){
            dp[i][j] = true;
            setColors(part[i][1], part[i][0]);
        }
    }
    return dp[i][j];
}

bool bipartite(int i, vector<int> &r, vector<int> &b){
    stack<int> s;
    s.push(i);
    c[i] = 1;
    r.push_back(i);

    while(!s.empty()){
        int u = s.top();
        s.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(c[u] == c[v]) 
                return false;
            else if(c[v] == -1){
                if(c[u] == 1){
                    c[v] = 2;
                    b.push_back(v);
                }
                else{
                    c[v] = 1;
                    r.push_back(v);
                }
                s.push(v);
            }
        }
    }
    return true;
}

bool bipartite(int i){
    part.push_back(vector<vector<int>>(2));
    return bipartite(i, part.back()[0], part.back()[1]);
}

int main(){
    optimize;

    cin >> n >> m >> n1 >> n2 >> n3;
    
    adj.resize(n);
    c.assign(n, -1);
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    bool ans = true;

    for(int i = 0; i < n && ans; i++){
        if(c[i] == -1)
            ans &= bipartite(i);
    }

    dp.assign(part.size() + 1, vector<int>(n2 + 1, -1));
    
    if(ans && solveDp(0, n2)){
        cout << "YES" << "\n";
        for(int i = 0; i < n; i++)
            cout << c[i];
        cout << "\n";
    }
    else
        cout << "NO" << "\n";
    
    return 0;   
}
