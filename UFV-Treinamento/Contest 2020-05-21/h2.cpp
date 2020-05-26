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
    vector<string> m(h);
    vector<vector<ll>> v1(h, vector<ll>(w, 0));
    vector<vector<ll>> v2(w, vector<ll>(h, 0));
    for(int i = 0; i < h; i++)
        cin >> m[i];
    for(int i = 0; i < h; i++){
        for(int j = 1; j < w; j++){
            v1[i][j] = v1[i][j - 1];
            if(m[i][j] == '.' && m[i][j - 1] == '.')
                v1[i][j]++;
        }
    }

    for(int i = 0; i < w; i++){
        for(int j = 1; j < h; j++){
            v2[i][j] = v2[i][j - 1];
            if(m[j][i] == '.' && m[j - 1][i] == '.')
                v2[i][j]++;
        }
    }

    cin >> q;
    while(q--){
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        ll ans = 0;
        for(int i = r1 - 1; i < r2; i++){
            ans += v1[i][c2 - 1] - v1[i][c1 - 1];
            cerr << ans << "\n";
        }

        cerr << "\n";

        for(int i = c1 - 1; i < c2; i++){
            ans += v2[i][r2 - 1] - v2[i][r1 - 1];
            cerr << ans << "\n";
        }

        cout << ans << "\n";
    }

    return 0;   
}