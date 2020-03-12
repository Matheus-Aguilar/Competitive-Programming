#include<bits/stdc++.h>
#define INF 1e8

using namespace std;

int dijkstra(int s, vector<vector<pair<int,int>>> &adj){
    vector<pair<int,int>>d(adj.size());
    vector<bool>v(adj.size(), false);
    for(int i = 0; i < adj.size(); i++)
        d[i] = make_pair(INF, i);
    
    d[s].first = 0;

    set<pair<int,int>> pq;
    for(int i = 0; i < d.size(); i++)
        pq.insert(d[i]);
    
    while(!pq.empty()){
        int cur = pq.begin()->second;
        v[cur] = true;
        pq.erase(pq.begin());

        for(int i = 0; i < adj[cur].size(); i++){
            pair<int, int> viz = adj[cur][i];
            if(!v[viz.first] && d[viz.first].first > d[cur].first + viz.second){
                pq.erase(d[viz.first]);
                d[viz.first].first = d[cur].first + viz.second;
                pq.insert(d[viz.first]);
            }
        }
    }
    int maxi = 0, mini = INF;
    for(int i = 0; i < d.size(); i++){
        if(i != s){
            maxi = max(maxi, d[i].first);
            mini = min(mini, d[i].first);
        }
    }
    return maxi - mini;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    while(m--){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        --a; --b;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    int s;
    cin >> s;
    --s;
    cout << dijkstra(s, adj) << endl;
}