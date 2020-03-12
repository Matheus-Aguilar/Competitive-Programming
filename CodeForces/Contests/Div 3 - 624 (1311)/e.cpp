#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    int t, n, d;
    cin >> t;

    while(t--){
        cin >> n >> d;
        vector<int> parent(n + 1);
        vector<vector<int>> child(n + 1);
        vector<int> height(n + 1);
        priority_queue<pii> leaves;
        
        parent[1] = 1;
        height[1] = 0;

        int sum = 0;
        
        for(int i = 2; i <= n; i++){
            height[i] = log2(i);
            parent[i] = (1 << (height[i] - 1)) + (i % (1 << height[i]))/2;
            child[parent[i]].push_back(i);
            sum += height[i];
        }

        for(int i = 1; i <= n; i++){
            if(!child[i].size()){
                leaves.push(pii(height[i], i));
            }
        }

        while(leaves.size() > 1 && sum < d){
            pii l1 = leaves.top();
            leaves.pop();
            pii l2 = leaves.top();
            leaves.pop();

            if(l1.first != l2.first){
                leaves.push(l1);
            }

            while(l1.first != l2.first){
                int parentCur = parent[l1.second];
                l1.first = height[parentCur];
                l1.second = parentCur;
            }

            child[parent[l2.second]].pop_back(); 
            if(child[parent[l2.second]].size() == 0){
                leaves.push(pii(height[parent[l2.second]], parent[l2.second]));
            }

            parent[l2.second] = l1.second;
            height[l2.second] = l2.first = l1.first + 1;
            child[l1.second].push_back(l2.second);
            leaves.push(l2);

            sum++;
        }

        if(sum != d){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
            for(int i = 2; i <= n; i++) cout << parent[i] << " ";
            cout << "\n";
        }
    }

    return 0;   
}
