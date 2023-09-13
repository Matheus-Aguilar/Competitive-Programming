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
        int n;
        cin >> n;

        vector<vector<int>> a(n);

        for(int i = 0; i < n; i++){
            
            int m;
            cin >> m;

            a[i].resize(m);

            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }

            sort(all(a[i]));
        }

        ll ans = 0;
        int small1 = INF, small2 = INF;

        for(int i = 0; i < n; i++){
            ans += a[i][1];
            small1 = min(small1, a[i][0]);
            small2 = min(small2, a[i][1]);
        }

        ans += small1;
        ans -= small2;
        
        cout << ans << "\n";
    }
    
    return 0;   
}
