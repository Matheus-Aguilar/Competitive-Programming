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
        int n, k, d;
        cin >> n >> k;
        d = (n - k)/2;
        bool ans = true;
        if(k > n) ans = false;
        if((n - k) % 2 != 0) ans = false;
        if(2LL * d < ((ll)k) * k - k) ans = false;
        cout << (ans ? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
