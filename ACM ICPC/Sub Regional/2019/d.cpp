#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visit;
vector<int> heights;
vector<pii> leaves;
priority_queue<int, vector<int>, greater<int>> pq;

void getHeights(int root){
    
    heights[root] = 1;
    stack<int> s;
    s.push(root);

    while(!s.empty()){
        int cur = s.top();
        s.pop();

        if(adj[cur].size()){
            for(int v:adj[cur]){
                heights[v] = heights[cur] + 1;
                s.push(v);
            }
        }
        else{
            leaves.push_back(pii(heights[cur], cur));
        }
    }
}

int denounce(int v){
    int newHeight = 0;
    while(!visit[v]){
        visit[v] = true;
        v = parent[v];
        newHeight++;
    }
    return newHeight;
}

int main(){
    optimize;

    int n, k;
    cin >> n >> k;

    adj.resize(n);
    parent.resize(n);
    visit.assign(n, false);
    heights.resize(n);

    for(int i = 1; i < n; i++){
        int v;
        cin >> v;
        --v;
        adj[v].push_back(i);
        parent[i] = v;
    }

    parent[0] = 0;

    getHeights(0);
    sort(leaves.begin(), leaves.end(), greater<pii>());

    for(int i = 0; i < leaves.size(); i++){
        int members = denounce(leaves[i].second);
        pq.push(members);
        if(pq.size() > k) pq.pop();
    }

    int ans = 0;

    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout << ans << "\n";

    return 0;   
}
