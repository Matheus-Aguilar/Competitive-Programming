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
    t = 1;

    while(t--){
        int n;
        bool ok = true;

        cin >> n;

        vector<vector<int>> a(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
            cin >> a[i][i];

        for(int i = n - 1; i >= 0 && ok; i--){
            
            int v = a[i][i];
            int cont = v - 1;
            int x = i;
            int y = i;

            while(cont > 0 && ok){
                
                if(x + 1 < n && a[x + 1][y] == -1)
                    x++;
                else if(y - 1 >= 0 && a[x][y - 1] == -1)
                    y--;
                else
                    ok = false;
                
                a[x][y] = v;
                cont--;
            }
        }

        if(!ok){
            cout << -1 << "\n";
            continue;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                cout << a[i][j] << " \n"[i==j];
            }
        }
    }

    return 0;   
}
