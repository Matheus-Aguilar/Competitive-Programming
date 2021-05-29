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

using namespace std;

int q, x[MAXN], ans[MAXN];
char type[MAXN];

vector<int> adj[MAXN];
deque<int> d;

void dfs(int u, int p = -1){
    
    //Apply update
    if(type[u] == 'E'){
        d.push_back(x[u]);
    }
    else if(type[u] =='D'){
        ans[u] = d.front();
        d.pop_front();
    }

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v != p)
            dfs(v, u);
    }

    //Remove update
    if(type[u] == 'E'){
        d.pop_back();
    }
    else if(type[u] =='D'){
        d.push_front(ans[u]);
    }
}

int main(){
    optimize;
    
    cin >> q;

    for(int i = 1; i <= q; i++){
        
        int v;
        
        cin >> type[i] >> v;

        adj[v].push_back(i);

        if(type[i] == 'E')
            cin >> x[i];
    }

    type[0] = 'X';

    dfs(0);

    for(int i = 1; i <= q; i++)
        if(type[i] == 'D')
            cout << ans[i] << "\n";

    return 0;   
}
