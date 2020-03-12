#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

bool check(int guess, vector<vector<int>> &value){
    for(int i = 0; i < value[0].size(); i++){
        int cont = 0;
        for(int j = 0; j < value.size(); j++){
            if(value[j][i] >= guess)
                cont++;
            else
                cont = 0;
            if(cont == guess)
                return true;
        }
    }
    return false;
}

int bin_search(int start, int end, vector<vector<int>> &value){
    while(start < end){
        int middle = (start + end)/2;
        bool possible = check(middle, value);

        if(possible)
            start = middle + 1;
        else
            end = middle;
    }

    return start - 1;
}

int main(){
    
    optimize;

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> value(n, vector<int>(m, 1));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++)
            value[i][j] = grid[i][j - 1] != grid[i][j] ? 1 : value[i][j - 1] + 1;
    
    int best = bin_search(1, min(n, m) + 1, value);

    cout << best * best << "\n";

    return 0;
}