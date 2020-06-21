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

int n, m;
vector<string> mapa;

void bt(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m || mapa[i][j] == '.')
        return;
    mapa[i][j] = '.';
    bt(i - 1, j);
    bt(i + 1, j);
    bt(i, j - 1);
    bt(i, j + 1);
    cout << i + 1 << " " << j + 1 << "\n";
    exit(0);
}

int main(){
    optimize;
    
    cin >> n >> m;
    mapa.resize(n);
    for(int i = 0; i < n; i++)
        cin >> mapa[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mapa[i][j] == 'o')
                bt(i, j);
    return 0;   
}
