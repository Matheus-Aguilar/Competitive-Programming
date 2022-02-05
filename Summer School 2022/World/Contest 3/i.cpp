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
#define fi first
#define se second

using namespace std;

int n, m;

int main(){
    //optimize;
    
    while(cin >> n >> m){
        
        vector<pii> p(m);

        if(m == 0){
            cout << n + 1 << "\n";
            continue;
        }

        for(int i = 0; i < m; i++){
            cin >> p[i].fi >> p[i].se;
        }
        
        sort(all(p));
        
        ll ans = n + 1;

        pii cur = p[0];

        for(int i = 1; i < m; i++){

            if(p[i].fi > p[i].se)
                continue;

            if(p[i].fi <= cur.se){
                cur.se = max(p[i].se, cur.se);
            }
            else{
                ans += 2 * (cur.se - cur.fi);
                cur = p[i];
            }
        }

        ans += 2 * (cur.se - cur.fi);

        cout << ans << endl;
    }

    return 0;   
}
