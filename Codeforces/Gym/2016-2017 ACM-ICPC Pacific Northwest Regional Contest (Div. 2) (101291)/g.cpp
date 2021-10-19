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

    int n, m;
    cin >> n >> m;

    vector<string> g(n);

    for(int i = 0; i < n; i++)
        cin >> g[i];

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'o'){
                
                int h = i + 1;

                while(h < n && g[h][j] == '.'){
                    h++;
                }

                g[i][j] = '.';
                g[h - 1][j] = 'o';
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << g[i] << "\n";
    
    return 0;   
}
