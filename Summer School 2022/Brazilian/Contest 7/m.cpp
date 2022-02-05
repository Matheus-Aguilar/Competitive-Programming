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

int n;
char g[10][10], m[10][10];
bool ok = false;

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << g[i][j];
        }
        cout << "\n";
    }
}

bool checkLine(int x, char ca, char cb){
    
    char aux = '\0';

    int a = ca - '0';
    int b = cb - '0';

    int cont = 0;

    for(int i = 0; i < n; i++){
        if(aux < g[x][i]){
            aux = g[x][i];
            cont++;
        }
    }

    aux = -1;
    int cont2 = 0;

    for(int i = n - 1; i >= 0; i--){
        if(aux < g[x][i]){
            aux = g[x][i];
            cont2++;
        }
    }

    for(int i = 0; i < n; i++){
        if(m[x+1][i+1] != '-' && m[x+1][i+1] != g[x][i])
            return false;
    }

    if(ca == '-')
        a = cont;
    if(cb == '-')
        b = cont2;

    //cout << a << " " << b << " " << cont << " " << cont2 << "\n";

    return a == cont && b == cont2;
}

bool checkCol(int x, char ca, char cb){
    
    
    char aux = '\0';

    int a = ca - '0';
    int b = cb - '0';

    int cont = 0;

    for(int i = 0; i < n; i++){
        if(aux < g[i][x]){
            aux = g[i][x];
            cont++;
        }
    }

    aux = -1;
    int cont2 = 0;

    for(int i = n - 1; i >= 0; i--){
        if(aux < g[i][x]){
            aux = g[i][x];
            cont2++;
        }
    }

    if(ca == '-')
        a = cont;
    if(cb == '-')
        b = cont2;

    return a == cont && b == cont2;
}

bool checkCol2(int x, int k){

    int mask = 0;

    for(int i = 0; i < k; i++){
        mask |= (1 << (g[i][x] - '0'));
    }

    return __builtin_popcount(mask) == k;
}

bool checkCols(){
    for(int i = 0; i < n; i++){
        if(!checkCol(i, m[0][i+1], m[n+1][i+1]))
            return false;
    }
    return true;
}

bool checkCols2(int k){
    for(int i = 0; i < n; i++){
        if(!checkCol2(i, k))
            return false;
    }
    return true;
}

void bt(int x){

    //cout << x << "\n";

    if(ok) return;

    if(x == n){
        if(checkCols()){
            ok = true;
        }
        return;
    }

    do {
        //cout << "LINE\n";

        if(!checkLine(x, m[x+1][0], m[x+1][n + 1]))
            continue;

        //cout << "COL\n";

        if(!checkCols2(x + 1))
            continue;
        
        bt(x + 1);

        if(ok) break;

    } while(next_permutation(g[x], g[x] + n));
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        cin >> n;

        ok = false;

        for(int i = 0; i < n + 2; i++){
            for(int j = 0; j < n + 2; j++){
                cin >> m[i][j];
            }    
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                g[i][j] = (j + 1) + '0';
            }    
        }

        bt(0);

        if(!ok)
            cout << "no" << "\n";
        else{
            print();
        }
        cout << "\n";
    }

    return 0;   
}
