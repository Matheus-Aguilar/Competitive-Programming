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

int main(){
    optimize;

    int a, b, W, diff;
    bool ok = false;

    cin >> W >> a >> b;

    --a, --b;

    vector<vector<char>> m(3, vector<char>(W, '.')), aux;

    m[0][a] = 'A';
    m[2][b] = 'B';
    m[1][0] = 'X';

    diff = abs(b - a);

    if(diff % 2 == 0){
        if(diff == 0){
            ok = true;
        }
        else if(diff == 2 && min(a, b) > 1){
            if(a < b){
                m[0][a - 1] = '*';
                m[1][a - 1] = '*';
            }
            else{
                m[1][b - 1] = '*';
                m[2][b - 1] = '*';
            }

            ok = true;
        }
        else if(diff >= 4 && min(a, b) != 0){
            m[0][a - 1] = '*';
            m[2][b - 1] = '*';

            for(int i = min(a, b); i < min(a, b) + diff/2; i++)
                m[1][i] = '*';
            
            ok = true;
        }
    }

    cout << (ok ? "Possible" : "Impossible") << "\n";

    for(int i = 0; i < 3 && ok; i++)
        for(int j = 0; j < W; j++)
            cout << m[i][j] << (j == W - 1 ? "\n" : "");

    return 0;   
}
