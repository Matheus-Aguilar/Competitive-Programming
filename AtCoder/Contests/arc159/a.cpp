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
#define MAXN 110

using namespace std;

int n, k, q, a[MAXN][MAXN], dist[MAXN][MAXN];

int main(){
    optimize;
    
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            dist[i][j] = (a[i][j] ? 1 : INF);
        }
    }

    for(int x = 0; x < n; x++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][j]);
            }
        }
    }

    cin >> q;

    while(q--){
        ll s, t;
        cin >> s >> t;

        s--;
        t--;

        s %= n;
        t %= n;

        cout << (dist[s][t] == INF ? -1 : dist[s][t]) << "\n";
    }

    return 0;   
}
