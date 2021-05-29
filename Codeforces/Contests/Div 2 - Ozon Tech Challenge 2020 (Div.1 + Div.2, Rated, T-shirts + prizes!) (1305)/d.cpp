#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>
#define MAXN 1010

using namespace std;

int n;
char value[MAXN][MAXN];
pii ending[MAXN][MAXN];

void bfs(int i, int j){

    queue<pii> q;
    q.push(pii(i, j));
    
    if(ending[i][j].first < 0){
        if(i > 0 && ending[i - 1][j] == ending[i][j])
            value[i][j] = 'U';
        else if(i < n - 1 && ending[i + 1][j] == ending[i][j])
            value[i][j] = 'D';
        else if(j > 0 && ending[i][j - 1] == ending[i][j])
            value[i][j] = 'L';
        else if(j < n - 1 && ending[i][j + 1] == ending[i][j])
            value[i][j] = 'R';
        else
            return;
    }
    else{
        value[i][j] = 'X';
    }

    while(!q.empty()){
        pii cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();

        if(x > 0 && ending[x - 1][y] == ending[x][y] && value[x - 1][y] == 0){
            value[x - 1][y] = 'D';
            q.push(pii(x - 1, y));
        }
        if(x < n - 1 && ending[x + 1][y] == ending[x][y] && value[x + 1][y] == 0){
            value[x + 1][y] = 'U';
            q.push(pii(x + 1, y));
        }
        if(y > 0 && ending[x][y - 1] == ending[x][y] && value[x][y - 1] == 0){
            value[x][y - 1] = 'R';
            q.push(pii(x, y - 1));
        }
        if(y < n - 1 && ending[x][y + 1] == ending[x][y] && value[x][y + 1] == 0){
            value[x][y + 1] = 'L';
            q.push(pii(x, y + 1));
        }
    }
}

bool solveLoop(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ending[i][j].first < 0 && value[i][j] == 0){
                bfs(i, j);
                if(value[i][j] == 0) return false;
            }
        }
    }
    return true;
}

bool solveNonLoop(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ending[i][j].first == i && ending[i][j].second == j){
                bfs(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(value[i][j] == 0){
                return false;
            }
        }
    }

    return true;
}

bool solve(){
    if(!solveLoop()) return false;
    if(!solveNonLoop()) return false;
    return true;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x, y;
            cin >> x >> y;
            ending[i][j] = pii(x - 1, y - 1);
        }
    }

    if(solve()){
        cout << "VALID" << "\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << value[i][j];
            }
            cout << "\n";
        }
    }
    else
        cout << "INVALID" << "\n";

    return 0;   
}
