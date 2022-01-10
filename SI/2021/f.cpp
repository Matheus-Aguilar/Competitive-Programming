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
#define MAXN 1010

using namespace std;

int n, m;

bool v[MAXN][MAXN];
char c[MAXN][MAXN];

void flood(int i, int j){
    
    if(i < 0 || j < 0 || i >= n || j >= m || c[i][j] == '0' || v[i][j])
        return;

    v[i][j] = true;

    flood(i, j + 1);
    flood(i, j - 1);
    flood(i + 1, j);
    flood(i - 1, j);
}

int main(){
    optimize;
    
    ms(v, false);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        if(!v[i][0] && c[i][0] == '1'){
            flood(i, 0);
        }
    }

    for(int i = 0; i < n; i++){
        if(!v[i][m-1] && c[i][m-1] == '1'){
            flood(i, m-1);
        }
    }

    for(int i = 0; i < m; i++){
        if(!v[0][i] && c[0][i] == '1'){
            flood(0, i);
        }
    }

    for(int i = 0; i < m; i++){
        if(!v[n-1][i] && c[n-1][i] == '1'){
            flood(n-1, i);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j];
        }
        cout << "\n";
    }

    return 0;   
}
