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

void bfs(vector<int> &dist, vector<int> &parent, vector<bool> &hotel, vector<int> &deg){
    queue<int> q;
    vector<bool> v(dist.size(), false);
    
    v[0] = true;

    for(int i = 1; i <= hotel.size(); i++){
        if(hotel[i]){
            q.push(i);
            dist[i] = 1;
            v[i] = true;
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(!v[parent[u]] && deg[parent[u]] <= 1){
            v[parent[u]] = true;
            dist[parent[u]] = dist[u] + 1;
            q.push(parent[u]);
        }
    }
}

int main(){
    optimize;

    int n, best = 0;
    cin >> n;

    vector<int> parent(n + 1);
    vector<int> nxt(n + 1, 0);
    vector<bool> hotel(n + 1);
    vector<int> dist(n + 1, 0);
    vector<int> deg(n + 1, 0);

    for(int i = 1; i <= n; i++){
        bool aux;
        cin >> aux;
        hotel[i] = aux;
    }
    for(int i = 1; i <= n; i++){
        cin >> parent[i];
        nxt[parent[i]] = i;
        deg[parent[i]]++;
    }

    bfs(dist, parent, hotel, deg);

    vector<int>::iterator it = max_element(all(dist));

    cout << *it << "\n";
    
    int pos = it - dist.begin();
    while(pos && deg[pos] <= 1){
        cout << pos << " ";
        pos = nxt[pos];
    }

    cout << "\n";

    return 0;   
}
