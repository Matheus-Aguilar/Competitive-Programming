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
    
    while(cin >> n >> m){
        
        if(n == 0 && m == 0)
            break;

        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> cont(m, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                
            }
        }
    }

    return 0;   
}
