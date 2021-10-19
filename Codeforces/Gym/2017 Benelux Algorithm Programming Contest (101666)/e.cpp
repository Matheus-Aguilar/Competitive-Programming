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
#define MAXN 300

using namespace std;

int n, b, r, xb[MAXN], yb[MAXN], xr[MAXN], yr[MAXN], pb[MAXN], pr[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

bool dfs(int u){
    vis[u] = true;

    if(u == 0) return true;

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];

        if(!vis[pr[v]] && dfs(pr[v])){
            pb[u] = v;
            pr[v] = u;
            return true;
        }
    }
    return false;
}

int kuhn(){

    ms(pb, 0);
    ms(pr, 0);

    int result = 0;

    for(int i = 1; i <= b; i++){
        ms(vis, false);
        if(pb[i] == 0 && dfs(i)) 
            result++;
    }

    return result;
}

bool check(double x){

    for(int i = 1; i <= b; i++){
        adj[i].clear();
    }

    for(int i = 1; i <= b; i++){
        for(int j = 1; j <= r; j++){
            double d = sqrt(pow(xb[i] - xr[j], 2) + pow(yb[i] - yr[j], 2));

            if(d <= x){
                adj[i].push_back(j);
            }
        }
    }

    return (b + r) - kuhn() >= n;
}

double binSearch(double l, double r){
    
    for(int i = 0; i < 150; i++){
        double m = l + (r - l) / 2.0;

        if(check(m))
            l = m;
        else
            r = m;
    }

    return l;
}

int main(){
    optimize;

    cin >> n >> b >> r;

    for(int i = 1; i <= b; i++)
        cin >> xb[i] >> yb[i];
    
    for(int i = 1; i <= r; i++)
        cin >> xr[i] >> yr[i];
    
    cout << fixed << setprecision(9) << binSearch(0.0, 1e9) << "\n";

    return 0;   
}
