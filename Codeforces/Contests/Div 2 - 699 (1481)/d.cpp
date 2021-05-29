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

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        bool ok = false;

        vector<vector<char>> adj(n, vector<char>(n));
        vector<int> sol(m + 1);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> adj[i][j];

        for(int i = 0; i < n && !ok; i++){
            for(int j = i + 1; j < n && !ok; j++){
                if(adj[i][j] == adj[j][i]){
                    
                    ok = true;

                    for(int k = 0; k <= m; k++){
                        if(k % 2 == 0){
                            sol[k] = i + 1;
                        }
                        else{
                            sol[k] = j + 1;
                        }
                    }
                }
            }
        }

        if(m % 2 != 0 && !ok){

            ok = true;

            for(int k = 0; k <= m; k++){
                if(k % 2 == 0){
                    sol[k] = 1;
                }
                else{
                    sol[k] = 2;
                }
            }
        }
        else{
            for(int i = 0; i < n && !ok; i++){
                
                int aIn = -1, bIn = -1, aOut = -1, bOut = -1, x, y, z;

                for(int j = 0; j < n && (aIn == -1 || bIn == -1); j++){
                    if(adj[j][i] == 'a')
                        aIn = j;
                    else if(adj[j][i] == 'b')
                        bIn = j;
                }

                for(int j = 0; j < n && (aOut == -1 || bOut == -1); j++){
                    if(adj[i][j] == 'a')
                        aOut = j;
                    else if(adj[i][j] == 'b')
                        bOut = j;
                }

                if(aIn != -1 && aOut != -1){
                    x = aIn;
                    y = i;
                    z = aOut;
                }
                else if(bIn != -1 && bOut != -1){
                    x = bIn;
                    y = i;
                    z = bOut;
                }
                else{
                    continue;
                }

                ok = true;

                if(m % 4 != 0){
                    for(int k = 0; k <= m; k++){
                        if(k % 4 == 0)
                            sol[k] = x + 1;
                        else if(k % 4 == 1)
                            sol[k] = y + 1;
                        else if(k % 4 == 2)
                            sol[k] = z + 1;
                        else
                            sol[k] = y + 1;
                    }
                }
                else{
                    for(int k = 0; k <= m; k++){
                        if(k % 4 == 0)
                            sol[k] = y + 1;
                        else if(k % 4 == 1)
                            sol[k] = z + 1;
                        else if(k % 4 == 2)
                            sol[k] = y + 1;
                        else
                            sol[k] = x + 1;
                    }
                }
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";

        for(int i = 0; i <= m && ok; i++)
            cout << sol[i] << " \n"[i==m];
    }
    
    return 0;   
}
