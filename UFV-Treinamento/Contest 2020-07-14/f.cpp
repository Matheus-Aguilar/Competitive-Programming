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

    int n, x = 0, prefix = 0, suffix = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        x ^= a[i];
    }

    unordered_map<int, int> even;
    unordered_map<int, int> odd;
    
    even[prefix]++;
    for(int i = 0; i < n; i++){
        prefix ^= a[i];
        if(i % 2 == 0)
            odd[prefix]++;
        else
            even[prefix]++;
    }

    ll ans = 0;

    if(n % 2 == 0)
        ans = even[x];
    else
        ans = odd[x];
        
    for(int i = n - 1; i >= 0; i--){
        
        suffix ^= a[i];
        
        if(i % 2 == 0)
            odd[prefix]--;
        else
            even[prefix]--;
        
        prefix ^= a[i];
        
        if(i % 2 == 0)
            ans += even[x ^ suffix];
        else
            ans += odd[x ^ suffix];
    }

    cout << ans - n - 1 << "\n";

    return 0;   
}
