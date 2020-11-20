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
#define MAXN 1110

using namespace std;

struct Edge{
    int from, to, d, k, v;
    Edge(int _from = 0, int _to = 0, int _d = 0, int _k = 0, int _v = 0) : from(_from), to(_to), d(_d), k(_k), v(_v){}
};

int n, m, kmax, vmax;
int dist[MAXN][21][21];
Edge e[MAXN];

void bellmanFord(int s){
    ms(dist, INF);

    dist[s][0][0] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int from = e[j].from, to = e[j].to, d = e[j].d, k = e[j].k, v = e[j].v;
            for(int ki = 0; ki + k <= kmax; ki++){
                for(int vi = 0; vi + v <= vmax; vi++){
                    dist[to][ki + k][vi + v] = min(dist[to][ki + k][vi + v], dist[from][ki][vi] + d);
                }
            }
        }
    }
}

int main(){
    optimize;

    cin >> n >> m >> kmax >> vmax;

    for(int i = 0; i < m; i++)
        cin >> e[i].from >> e[i].to >> e[i].d >> e[i].k >> e[i].v;

    bellmanFord(0);

    pii best = pii(INF, INF);

    for(int ki = 0; ki <= kmax; ki++){
        for(int vi = 0; vi <= vmax; vi++){
            best = min(best, pii(dist[n - 1][ki][vi], ki + vi));
        }
    }

    if(best.first == INF)
        cout << -1 << " " << -1 << "\n";
    else
        cout << best.first << " " << kmax + vmax - best.second << "\n";

    return 0;   
}
