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

using namespace std;

int h, w, m[110][110];
char g[110][110];
bool ok = true, v[110][110];

void print(){
    
    for(int i = 0; i < h + 2; i++){
        for(int j = 0; j < w + 2; j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cout << g[i][j];
        }
        cout << "\n";
    }

    cout << "\n";

    cout << ok << "\n\n";
}

void setPos(int x, int y, bool c){
    
    if(g[x][y] != '$')
        return;
    
    g[x][y] = (c ? 'X' : '.');

    if(c){
        for(int i = x - 1; i <= x + 1; i++){
            for(int j = y - 1; j <= y + 1; j++){
                m[i][j]--;
                ok &= (m[i][j] >= 0);
            }   
        }
    }
}

void solve(int i1, int i2, int j1, int j2){
    for(int j = j1; j <= j2; j++){
        
        if(v[i1][j]) continue;
        
        if(m[i1][j] && m[i1][j] == 1)
            setPos(i1 + 1, j + 1, true);
        else
            setPos(i1 + 1, j + 1, false);

        v[i1][j] = true;
    }
    for(int j = j1; j <= j2; j++){
        
        if(v[i2][j]) continue;
        
        if(m[i2][j] && m[i2][j] == 1)
            setPos(i2 - 1, j + 1, true);
        else
            setPos(i2 - 1, j + 1, false);

        v[i2][j] = true;
    }
    for(int i = i1; i <= i2; i++){
        
        if(v[i][j1]) continue;
        
        if(m[i][j1] && m[i][j1] == 1)
            setPos(i + 1, j1 + 1, true);
        else
            setPos(i + 1, j1 + 1, false);

        v[i][j1] = true;
    }
    for(int i = i1; i <= i2; i++){
        
        if(v[i][j2]) continue;
        
        if(m[i][j2] && m[i][j2] == 1)
            setPos(i + 1, j2 - 1, true);
        else
            setPos(i + 1, j2 - 1, false);

        v[i][j2] = true;
    }
}

int main(){
    optimize;

    cin >> h >> w;

    for(int i = 0; i < h + 2; i++){
        for(int j = 0; j < w + 2; j++){
            cin >> m[i][j];
            g[i][j] = '$';
        }
    }

    int i1 = 0, i2 = h + 1, j1 = 0, j2 = w + 1;

    while(i1 < i2 && j1 < j2){
        
        solve(i1, i2, j1, j2);
        
        i1++;
        i2--;
        j1++;
        j2--;
    }

    for(int i = 0; i < h + 2; i++){
        for(int j = 0; j < w + 2; j++){
            ok &= (m[i][j] == 0);
        }
    }

    if(!ok)
        cout << "impossible" << "\n";
    else{
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cout << g[i][j];
            }
            cout << "\n";
        }
    }

    return 0;   
}
