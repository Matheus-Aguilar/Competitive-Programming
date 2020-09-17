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
        ll x;
        int n, i;

        cin >> x >> n;

        if(n == 1)
            cout << x << "\n";
        else{

            vector<ll> ans(n, x/(2 * n - 2));

            for(i = 1; i < n - 1; i++)
                ans[i] *= 2;
        
            i = 0;
            x %= 2 * n - 2;

            while(i < n && x-- > 0)
                ++ans[i++];
            
            i = n - 2;

            while(x-- > 0)
                ++ans[i--];

            for(int i = 0; i < n; i++)
                cout << ans[i] << " \n"[i==n-1];
        }
    }
    
    return 0;   
}
