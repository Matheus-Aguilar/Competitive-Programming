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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        sort(all(a));
        sort(all(b));
        reverse(all(b));
        int i = 0;
        ll ans = 0;
        while(i < k && a[i] < b[i]){
            ans += b[i];
            i++;
        }
        while(i < n){
            ans += a[i];            
            i++;
        }
        cout << ans << "\n";
    }
    
    return 0;   
}
