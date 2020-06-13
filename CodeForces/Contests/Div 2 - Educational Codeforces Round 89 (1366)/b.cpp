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
        int n, x, m;
        pii ans;
        cin >> n >> x >> m;
    
        ans = pii(x, x);
        while(m--){
            int l, r;
            cin >> l >> r;
            if(max(l, ans.first) <= min(r, ans.second)){
                ans.first = min(ans.first, l);
                ans.second = max(ans.second, r);
            }
        }
        cout << ans.second - ans.first + 1 << "\n";
    }

    return 0;   
}
