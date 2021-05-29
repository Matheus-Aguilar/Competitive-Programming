#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int ans = x * b;
        ans = max(ans, y * a);
        ans = max(ans, (a - x - 1) * b);
        ans = max(ans, (b - y - 1) * a);
        cout << ans << "\n";
    }

    return 0;   
}
