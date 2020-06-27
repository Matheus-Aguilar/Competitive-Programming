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
    
    ll n, t;
    cin >> n >> t;

    if(t == 0){
        cout << n << "\n";
    }
    else if(t == 1){
        cout << n * (n - 1) << "\n";
    }
    else{
        ll ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                ans += (j - i - 1);
        cout << ans << "\n";
    }

    return 0;   
}
