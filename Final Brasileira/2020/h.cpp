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

int n;
vector<int> adj[MAXN];
bool visit[MAXN];

void dfs(int u){
    visit[u] = true;

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];

        if(!visit[v]){
            dfs(v);
        }
    }
}

int main(){
    optimize;
    
    return 0;   
}
