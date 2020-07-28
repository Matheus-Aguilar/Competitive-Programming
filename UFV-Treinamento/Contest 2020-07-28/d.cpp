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

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> b[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] > b[i][j])
                swap(a[i][j], b[i][j]);

    bool ans = true;

    for(int i = 0; i < n && ans; i++){
        for(int j = 0; j < m && ans; j++){
            if(j > 0)
                ans &= (a[i][j - 1] < a[i][j]);
            if(i > 0)
                ans &= (a[i - 1][j] < a[i][j]);
        }
    }

    for(int i = 0; i < n && ans; i++){
        for(int j = 0; j < m && ans; j++){
            if(j > 0)
                ans &= (b[i][j - 1] < b[i][j]);
            if(i > 0)
                ans &= (b[i - 1][j] < b[i][j]);
        }
    }

    cout << (ans ? "Possible" : "Impossible") << "\n";

    return 0;   
}
