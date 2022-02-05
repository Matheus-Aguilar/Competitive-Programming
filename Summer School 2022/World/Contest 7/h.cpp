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
#define fi first
#define se second

using namespace std;

string findExit(int n, int m, vector<string> &g, pii f){
    
    vector<vector<char>> p(n, vector<char>(m, '$'));

    queue<pii> q;
    q.emplace(0, 0);

    p[0][0] = 'X';

    while(!q.empty()){
        pii u = q.front();
        int i = u.first, j = u.second;

        q.pop();

        if(i > 0 && p[i - 1][j] == '$' && g[i - 1][j] != '*'){
            p[i - 1][j] = 'U';
            q.emplace(i - 1, j);
        }
        if(i < n - 1 && p[i + 1][j] == '$' && g[i + 1][j] != '*'){
            p[i + 1][j] = 'D';
            q.emplace(i + 1, j);
        }
        if(j > 0 && p[i][j - 1] == '$' && g[i][j - 1] != '*'){
            p[i][j - 1] = 'L';
            q.emplace(i, j - 1);
        }
        if(j < m - 1 && p[i][j + 1] == '$' && g[i][j + 1] != '*'){
            p[i][j + 1] = 'R';
            q.emplace(i, j + 1);
        }
    }

    string s = "";
    
    while(f.first != 0 || f.second != 0){
        
        char c = p[f.first][f.second];
        
        s += c;

        if(c == 'L')
            f.second += 1;
        if(c == 'R')
            f.second -= 1;
        if(c == 'U')
            f.first += 1;
        if(c == 'D')
            f.first -= 1;
    }

    reverse(all(s));

    return s;
}

pii move(char type, bool swapLR, bool swapUD){
    
    if(swapLR){
        if(type == 'L')
            type = 'R';
        else if(type == 'R')
            type = 'L';
    }

    if(swapUD){
        if(type == 'U')
            type = 'D';
        else if(type == 'D')
            type = 'U';
    }

    cout << type << endl;

    int x, y;
    cin >> x >> y;

    return pii(x, y);
}

int main(){
    //optimize;

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for(int i = 0; i < n; i++)
        cin >> grid[i];
    
    pii f;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'F'){
                f = pii(i, j);
            }
        }
    }

    int x = 0, y = 0;
    bool swapLR = false, swapUD = false;

    string goal = findExit(n, m, grid, f);
    string path = "";
    
    pii now = pii(1, 1), nxt;

    for(int i = 0; i < goal.size(); i++){
        nxt = move(goal[i], swapLR, swapUD);

        if(nxt == now){
            if(goal[i] == 'D' || goal[i] == 'U'){
                swapUD = true;
            }
            else {
                swapLR = true;
            }
            i--;
        }

        now = nxt;
    }

    return 0;   
}
