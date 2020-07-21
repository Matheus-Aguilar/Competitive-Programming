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
#define MAXN 1010
#define fi first
#define se second

using namespace std;

struct Rectangle{
    int x1, y1, x2, y2;
    Rectangle(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0){
        x1 = min(_x1, _x2);
        y1 = min(_y1, _y2);
        x2 = max(_x1, _x2);
        y2 = max(_y1, _y2);
    }
    int dist(const Rectangle &r) const{
        int ans = 0;
        if(x2 < r.x1 || r.x2 < x1)
            ans += min(abs(x2 - r.x1), abs(x1 - r.x2));
        if(y2 < r.y1 || r.y2 < y1)
            ans += min(abs(y2 - r.y1), abs(y1 - r.y2));
        return ans;

    }
};

int n;
int dist[MAXN];
bool visit[MAXN];
int adj[MAXN][MAXN];

int dijkstra(int s, int t){
    
    ms(dist, INF);
    dist[s] = 0;

    while(!visit[t]){
        pii u = make_pair(INF + 1, -1);
        for(int i = 0; i < n + 2; i++)
            if(!visit[i])
                u = min(u, make_pair(dist[i], i));
        visit[u.se] = true;
        for(int i = 0; i < n + 2; i++)
            dist[i] = min(dist[i], dist[u.se] + adj[u.se][i]);
    }

    return dist[t];
}

int main(){
    optimize;

    int xi, yi, xf, yf;
    cin >> xi >> yi >> xf >> yf >> n;

    vector<Rectangle> r(n + 2);

    for(int i = 1; i <= n; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        r[i] = Rectangle(x1, y1, x2, y2);
    }

    r[0] = Rectangle(xi, yi, xi, yi);
    r[n + 1] = Rectangle(xf, yf, xf, yf);

    for(int i = 0; i < n + 2; i++)
        for(int j = 0; j < n + 2; j++)
            adj[i][j] = r[i].dist(r[j]);
    
    cout << dijkstra(0, n + 1) << "\n";

    return 0;   
}
