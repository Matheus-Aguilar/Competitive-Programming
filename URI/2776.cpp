#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &w, vector<int> &v, vector<bool> &valid, int c){
    
    vector<int>dp(c + 1, 0); //Initialize the knapsack

    valid[0] = true; //Just accepts knapsacks that are completely full

    /*Solving Unbounded Knapsack*/
    for(int i = 0; i <= c; i++){
        for(int j = 0; j < w.size(); j++){
            if(i - w[j] >= 0 && valid[i - w[j]]){
                dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
                valid[i] = true;
            }
        }
    }
    
    return dp[c];
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        vector<int>w(n);
        vector<int>v(n);
        vector<bool>valid(m + 1, false);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &w[i], &v[i]);
        printf("%d\n", knapsack(w, v, valid, m));
    }

    return 0;
}