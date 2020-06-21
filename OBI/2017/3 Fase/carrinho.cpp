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
#define MAXN 1100

using namespace std;

int n;
long double d;
long double adj[MAXN][MAXN];
long double c[MAXN];
long double p[MAXN];

long double dijkstra(int s, int t){
    long double dist[n + 1];
    bool visit[n + 1];
    
    for(int i = 0; i <= n; i++){
        dist[i] = INFLL;
        visit[i] = false;
    }

    dist[s] = 0;

    while(!visit[t]){
        int u = -1;
        for(int i = 0; i <= n; i++){
            if(!visit[i] && (u == -1 || dist[u] > dist[i]))
                u = i;
        }
        visit[u] = true;
        for(int i = 0; i <= n; i++){
            dist[i] = min(dist[i], dist[u] + adj[u][i]);
        }
    }

    return dist[t];
}

int main(){
    optimize;

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            adj[i][j] = INFLL;

    cin >> n >> d;
    
    for(int i = 0; i < n; i++)
        cin >> p[i] >> c[i];
    p[n] = d;

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j <= n; j++)
            adj[i][j] = ((p[j] - p[i]) * (p[j] - p[i]))/c[i];

    cout << fixed << setprecision(3) << dijkstra(0, n) << "\n";

    return 0;   
}
