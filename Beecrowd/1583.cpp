#include<bits/stdc++.h>

using namespace std;

void flood(int i, int j, vector<vector<char>> &grid, int n, int m){
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'A')
        return;
    grid[i][j] = 'T';
    flood(i - 1, j, grid, n, m);
    flood(i + 1, j, grid, n, m);
    flood(i, j - 1, grid, n, m);
    flood(i, j + 1, grid, n, m);
}

int main(){
    int n, m;
    while(cin >> n >> m){
        if(!m && !n) return 0;
        vector<vector<char>> grid(n, vector<char>(m));
        queue<pair<int, int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                if(grid[i][j] == 'T')
                    q.push(make_pair(i, j));
            }
        }

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            flood(p.first - 1, p.second, grid, n, m);
            flood(p.first + 1, p.second, grid, n, m);
            flood(p.first, p.second - 1, grid, n, m);
            flood(p.first, p.second + 1, grid, n, m);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << grid[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}