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
#define MAXN 200200

using namespace std;

int c, p, x, l, leave[MAXN], part[MAXN];
bool visit[MAXN];
vector<int> adj[MAXN];

bool solve(){

    queue<int> q;
    q.push(l - 1);

    while(!q.empty()){
        
        int u = q.front();
        q.pop();

        visit[u] = true;

        for(int i = 0; i < adj[u].size(); i++){
            
            int v = adj[u][i];
            
            leave[v]++;

            if(!visit[v] && leave[v] >= (part[v] + 1) / 2){
                visit[v] = true;
                q.push(v);
            }
        }
    }

    return visit[x - 1];
}

int main(){
    optimize;

    cin >> c >> p >> x >> l;

    for(int i = 0; i < p; i++){
        
        int u, v;
        cin >> u >> v;

        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);

        part[u - 1]++;
        part[v - 1]++;
    }

    cout << (solve() ? "leave" : "stay") << "\n";
    
    return 0;   
}
