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

    int h, w, q;
    cin >> h >> w;
    vector<string> m(h + 1);
    vector<vector<ll>> v1(h + 1, vector<ll>(w + 1, 0));
    vector<vector<ll>> v2(w + 1, vector<ll>(h + 1, 0));
    for(int i = 1; i <= h; i++){
        cin >> m[i];
        m[i] = '#' + m[i]; //Ajust the index
    }
    for(int i = 1; i <= h; i++){
        for(int j = 2; j <= w; j++){
            v1[i][j] = v1[i][j - 1];
            if(m[i][j] == '.' && m[i][j - 1] == '.')
                v1[i][j]++;
        }
        for(int j = 2; j <= w; j++)
            v1[i][j] += v1[i - 1][j];
    }

    for(int i = 1; i <= w; i++){
        for(int j = 2; j <= h; j++){
            v2[i][j] = v2[i][j - 1];
            if(m[j][i] == '.' && m[j - 1][i] == '.')
                v2[i][j]++;
        }
        for(int j = 2; j <= h; j++)
            v2[i][j] += v2[i - 1][j];
    }

    cin >> q;
    while(q--){
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << ((v1[r2][c2] - v1[r2][c1]) - (v1[r1 - 1][c2] - v1[r1 - 1][c1])) + ((v2[c2][r2] - v2[c2][r1]) - (v2[c1 - 1][r2] - v2[c1 - 1][r1])) << "\n";
    }

    return 0;   
}
