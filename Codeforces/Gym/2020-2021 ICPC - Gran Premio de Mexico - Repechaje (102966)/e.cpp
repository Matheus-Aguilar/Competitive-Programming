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
#define MAXN 1000100

using namespace std;

int n, m, q, p[MAXN], root, deg[MAXN], cnt[MAXN];
ll sum[MAXN], up[MAXN], subtree[MAXN];
vector<int> adj[MAXN], leaf;

void bfs(){
    
    ms(cnt, 0);
    queue<int> q;
    
    for(int i = 0; i < leaf.size(); i++)
        q.push(leaf[i]);

    while(!q.empty()){
        
        int u = q.front();
        q.pop();

        sum[u] += up[u];

        up[p[u]] += up[u];
        cnt[p[u]]++;

        if(deg[p[u]] == cnt[p[u]]){
            q.push(p[u]);
        }
    }
}

void bfs2(){
    
    ms(cnt, 0);
    queue<int> q;
    
    for(int i = 0; i < leaf.size(); i++)
        q.push(leaf[i]);

    while(!q.empty()){
        
        int u = q.front();
        q.pop();

        subtree[u] += sum[u];
        
        subtree[p[u]] += subtree[u];
        cnt[p[u]]++;

        if(deg[p[u]] == cnt[p[u]]){
            q.push(p[u]);
        }
    }
}

int main(){
    optimize;
    
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        cin >> p[i];
        deg[p[i]]++;
        
        if(p[i] == 0){
            root = i;
        }
    }

    for(int i = 1; i <= n; i++){
        if(deg[i] == 0){
            leaf.push_back(i);
        }
    }

    while(m--){
        
        int t, u, v;
        cin >> t >> u >> v;

        if(t == 1){
            sum[u] += v;
        } else {
            up[u] += v;
        }
    }

    bfs();
    bfs2();

    while(q--){
        int t, u;
        cin >> t >> u;
        cout << (t == 1 ? sum[u] : subtree[u]) << "\n";
    }

    return 0;   
}
