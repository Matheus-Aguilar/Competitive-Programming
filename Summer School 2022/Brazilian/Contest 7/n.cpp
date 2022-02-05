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
#define MAXN 100

using namespace std;

string s[MAXN];
ll x[MAXN], y[MAXN], z[MAXN];
double adj[MAXN][MAXN];

map<string, int> m;

double dist(int i, int j){
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]));
}

void floyd(int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main(){
    optimize;

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> s[i] >> x[i] >> y[i] >> z[i];
            m[s[i]] = i;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj[i][j] = adj[j][i] = dist(i, j);
            }   
        }

        int w;
        cin >> w;

        for(int i = 0; i < w; i++){
            string s1, s2;
            cin >> s1 >> s2;
            adj[m[s1]][m[s2]] = 0;
        }

        floyd(n);

        int q;
        cin >> q;

        cout << "Case " << t << ":\n";

        for(int i = 0; i < q; i++){
            string s1, s2;
            cin >> s1 >> s2;
            cout << "The distance from " << s1 << " to " << s2 << " is " << (ll) round(adj[m[s1]][m[s2]]) << " parsecs.\n";
        }

        m.clear();
    }
    
    return 0;   
}
