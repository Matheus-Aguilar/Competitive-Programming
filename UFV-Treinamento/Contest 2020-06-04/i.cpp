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

using namespace std;

int main(){
    optimize;
    
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        adj[i].push_back(s - 1);
        if(i != n - 1) adj[i].push_back(i + 1);
        if(i != 0) adj[i].push_back(i - 1);
    }

    vector<int> d(n, -1);
    d[0] = 0;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << "\n";

    return 0;   
}
