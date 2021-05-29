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
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        
        bool ans = true;
        
        for(int i = 0; i < n && ans; i++)
            for(int j = 0; j < m && ans; j++)
                ans &= (a[i][j] <= (i != 0) + (j != 0) + (i != n - 1) + (j != m - 1));
        
        if(ans){
            cout << "YES" << "\n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << (i != 0) + (j != 0) + (i != n - 1) + (j != m - 1) << " ";
                }
                cout << "\n";
            }
        }
        else
            cout << "NO" << "\n";
    }
    
    return 0;   
}
