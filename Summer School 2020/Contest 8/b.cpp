#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0xffffff
#define MAXN 510
using namespace std;

int adj[MAXN][MAXN];
int prefer[MAXN][MAXN];
int score[MAXN];

int main(){
    int m, n;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> score[j];
            if(!score[j]) score[j] = INF;
        }

        for(int j = 0; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(score[j] < score[k])
                    prefer[j][k]++;
                else if(score[j] > score[k])
                    prefer[k][j]++;
            }
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = (prefer[i][j] > prefer[j][i] ? prefer[i][j] : 0);
    
    //Floyd
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j)
                    adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
    
    priority_queue<int> solution;
    
    for(int i = 0; i < n; i++){
        bool valid = true;
        for(int j = 0; j < n; j++){
            if(adj[i][j] < adj[j][i])
                valid = false;
        }
        if(valid) solution.push(-i - 1);
    }

    while(!solution.empty()){
        cout << -solution.top() << " ";
        solution.pop();
    }

    cout << "\n";
}