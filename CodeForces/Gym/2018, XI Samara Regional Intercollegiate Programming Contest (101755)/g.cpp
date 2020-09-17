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

    int n, k;
    cin >> n >> k;

    ll ans = 0;

    vector<ll> a(n + 1);
    vector<ll> odd(n + 1, 0);
    vector<ll> even(n + 1, 0);
    
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++){
        
        if(i & 1)
            odd[i] = a[i]; 
        else
            even[i] = a[i];
        
        odd[i] += odd[i - 1]
        even[i] += even[i - 1];
    }

    for(int i = 1; i <= n; i++){
        
        if((i + k - 1) & 1)
            ans += odd[min(i + k - 1, n)] - odd[max(i - k, 0)];
        else
            ans += even[min(i + k - 1, n)] - even[max(i - k, 0)];
        
        ans -= k * a[i];
    }

    cout << ans << "\n";

    return 0;   
}
