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
#define MAXN 100100
#define MAXK 110

using namespace std;

int n, m, s, k;
vector<int> adj[MAXN];
int a[MAXN];
int dist[MAXN][MAXK];

void bfs(int ki){
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(a[i] == ki){
            q.push(i);
            dist[i][ki] = 0;
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(dist[v][ki] == -1){
                dist[v][ki] = dist[u][ki] + 1;
                q.push(v);
            }
        }
    }
}

int calc(int pos){
    int sum = 0;
    priority_queue<int> pq;
    for(int i = 0; i < k; i++){
        pq.push(dist[pos][i]);
        if(pq.size() > s)
            pq.pop();
    }
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    return sum;
}

int main(){
    optimize;

    cin >> n >> m >> k >> s;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    ms(dist, -1);
    for(int i = 0; i < k; i++)
        bfs(i);
    for(int i = 0; i < n; i++)
        cout << calc(i) << " \n"[i==n-1];

    return 0;   
}
