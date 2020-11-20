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

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> c(n, vector<int>(n, 0));
    vector<vector<int>> ans(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char aux;
            cin >> aux;
            a[i][j] = aux - '0';
        }
    }
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            if(a[i][j] != c[i][j]){
                ans[i][j] = 1;
                c[i][j] = (c[i][j] + 1) % 10;
                for(int k = j + 1; k < n; k++)
                    c[i][k] = (c[i][k] + c[j][k]) % 10;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;   
}
