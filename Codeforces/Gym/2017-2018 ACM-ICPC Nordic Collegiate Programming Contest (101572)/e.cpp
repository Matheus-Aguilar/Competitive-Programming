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
#define MAXN 250100

using namespace std;

int h, w, grid[MAXN];
bool visit[MAXN];

ll ans = 0;
pii mov[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}};

void solve(int s){
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(grid[s], s);

    while(!pq.empty()){
        
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(visit[u]) continue;

        visit[u] = true;
        ans += d;

        for(int i = 0; i < 8; i++){

            int a = u / w + mov[i].first;
            int b = u % w + mov[i].second;

            if(a < 0 || b < 0 || a >= h || b >= w) continue;

            int v = u + w * mov[i].first + mov[i].second;

            if(grid[v] < 0){
                pq.emplace(max(d, grid[v]), v);
            }
        }
    }
}

int main(){
    optimize;

    cin >> h >> w;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i * w + j];
        }
    }

    int a, b;
    cin >> a >> b;

    solve(a * w + b - w - 1);

    cout << -ans << "\n";
    
    return 0;   
}
