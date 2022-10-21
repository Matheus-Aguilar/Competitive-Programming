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
#define MAXN 2000

using namespace std;

int n, m, deg[MAXN], vis = 0;
map<string, int> id;
vector<int> adj[MAXN];
string known[MAXN], learn[MAXN];
vector<string> sadj[MAXN];

void toposort(){

    queue<int> q;

    for(int i = 0; i < n; i++){
        vis++;
        q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++){
            
            int v = adj[u][i];
            deg[v]--;

            if(deg[v] == 0){
                vis++;
                q.push(v);
            }
        }
    }
}

int main(){
    optimize;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> known[i];
        id[known[i]] = id.size();
    }

    cin >> m;

    for(int i = 0; i < m; i++){
        int k;

        cin >> learn[i] >> k;
        id[learn[i]] = id.size();

        for(int j = 0; j < k; j++){
            string s;
            cin >> s;
            sadj[id[learn[i]]].push_back(s);
        }
    }

    for(int i = 0; i < m; i++){
        int u = id[learn[i]];
        for(int j = 0; j < sadj[u].size(); j++){
            if(id.find(sadj[u][j]) != id.end()){
                int v = id[sadj[u][j]];
                adj[v].push_back(u);
            }
            deg[u]++;
        }
    }

    toposort();

    cout << vis << "\n";

    return 0;   
}
