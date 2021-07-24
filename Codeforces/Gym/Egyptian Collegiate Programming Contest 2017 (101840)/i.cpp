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

    ifstream in("important.in");

    int T;
    in >> T;

    for(int t = 1; t <= T; t++){
        
        cout << "Case " << t << ":\n";
    
        int n, m, q;
        in >> n >> m >> q;
    
        vector<vector<int>> mat(n + 1, vector<int>(m + 1));
        vector<vector<vector<int>>> row(n + 1, vector<vector<int>>(m + 1, vector<int>(2011, 0)));
        vector<vector<vector<int>>> block(n + 1, vector<vector<int>>(m + 1, vector<int>(2011, 0)));
        vector<int> query(2011, 0);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                in >> mat[i][j];
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                row[i][j] = row[i][j - 1];
                row[i][j][mat[i][j]]++;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 0; k <= 2010; k++){
                    block[i][j][k] = block[i - 1][j][k] + row[i][j - 1][k];
                } 
                block[i][j][mat[i][j]]++;
            }
        }

        while(q--){
            
            int a, b, c, d, med, sz;
            in >> a >> b >> c >> d;

            fill(all(query), 0);

            for(int k = 0; k <= 2010; k++)
                query[k] += block[c][d][k];
            for(int k = 0; k <= 2010; k++)
                query[k] -= block[c][b - 1][k];
            for(int k = 0; k <= 2010; k++)
                query[k] -= block[a - 1][d][k];
            for(int k = 0; k <= 2010; k++)
                query[k] += block[a - 1][b - 1][k];
        
            sz = ((c - a + 1) * (d - b + 1) + 2) / 2;

            for(int k = 0, acc = 0; k <= 2010; k++){
                
                acc += query[k];

                if(acc >= sz){
                    med = k;
                    break;
                }
            }

            cout << med << "\n";
        }
    }
    
    return 0;   
}
