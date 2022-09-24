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

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        
        int r, c;
        cin >> r >> c;

        vector<vector<char>> g(r, vector<char>(c));
        bool ok = true, hasTree = false;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> g[i][j];
                if(g[i][j] == '^')
                    hasTree = true;
            }
        }

        if(hasTree && (r == 1 || c == 1))
            ok = false;

        if(ok && hasTree){
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    g[i][j] = '^';
                }
            }
        }
        
        cout << "Case #" << t << ": " << (ok ? "Possible" : "Impossible") << "\n";

        for(int i = 0; i < r && ok; i++){
            for(int j = 0; j < c; j++){
                cout << g[i][j];
            }
            cout << "\n";
        }
    }
    
    return 0;   
}
