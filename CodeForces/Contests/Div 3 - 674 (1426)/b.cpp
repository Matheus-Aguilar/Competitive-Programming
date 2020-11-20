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

        vector<vector<int>> v(n, vector<int>(4));

        bool ok = false;

        for(int i = 0; i < n; i++){
            cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
            ok |= v[i][1] == v[i][2];
        }

        cout << (m % 2 == 0 && ok ? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
