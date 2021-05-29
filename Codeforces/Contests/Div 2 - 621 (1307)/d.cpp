#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 100000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    vector<pii> dist1(n);
    vector<pii> distN(n);
    vector<int> special(k);

    
    for(int i = 0; i < n; i++)
        dist1[i] = distN[i] = pii(INF, i);
    
    dist1[0] = pii(0, 0);
    distN[n - 1] = pii(0, n - 1);
    
    for(int i = 0; i < k; i++){
        cin >> special[i];
        --special[i];
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i:adj[cur]){
            if(dist1[i].first == INF){
                dist1[i].first = dist1[cur].first + 1;
                q.push(i);
            }
        }
    }

    q.push(n - 1);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i:adj[cur]){
            if(distN[i].first == INF){
                distN[i].first = distN[cur].first + 1;
                q.push(i);
            }
        }
    }

    vector<pii> specialDist(k);
    for(int i = 0; i < k; i++)
        specialDist[i] = pii(dist1[special[i]].first - distN[special[i]].first, special[i]);
    sort(specialDist.begin(), specialDist.end());
    
    int prefix = dist1[specialDist[0].second].first;
    int suffix = -1;
    int best = 0;

    for(int i = 1; i < k; i++){
        suffix = distN[specialDist[i].second].first + 1;
        best = max(best, prefix + suffix);
        prefix = max(prefix, dist1[specialDist[i].second].first);
    }

    cout << min(dist1[n - 1].first, best) << "\n";

    return 0;   
}
