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
        
        bool possible = false;
        int best = INF, cont = 0;

        int n;
        cin >> n;

        vector<int> rx(n, 0), ro(n, 0), re(n, 0);
        vector<int> cx(n, 0), co(n, 0), ce(n, 0);

        vector<vector<char>> cells(n, vector<char>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char cell;
                cin >> cell;

                if(cell == 'X'){
                    rx[i]++;
                    cx[j]++;
                } 
                else if(cell == 'O'){
                    ro[i]++;
                    co[j]++;
                }
                else {
                    re[i]++;
                    ce[j]++;
                }

                cells[i][j] = cell;
            }   
        }

        for(int i = 0; i < n; i++){
            if(ro[i] == 0){
                possible = true;
                
                if(best > re[i]){
                    best = re[i];
                    cont = 1;
                }
                else if(best == re[i]){
                    cont++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(co[i] == 0){
                possible = true;

                if(best > ce[i]){
                    best = ce[i];
                    cont = 1;
                }
                else if(best == ce[i]){
                    cont++;
                }
            }
        }

        if(!possible)
            cout << "Case #" << t << ": " << "Impossible" << "\n";
        else if(best != 1)
            cout << "Case #" << t << ": " << best << " " << cont << "\n";
        else{
            cont = 0;

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(cells[i][j] == '.' && (rx[i] == n - 1 || cx[j] == n - 1)){
                        cont++;
                    }
                }
            }

            cout << "Case #" << t << ": " << best << " " << cont << "\n";
        }
    }

    return 0;   
}
