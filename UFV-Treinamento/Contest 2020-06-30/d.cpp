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
        int n, x, big = 0, ans = -1;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            big = max(big, a[i]);
            if(a[i] == x)
                ans = 1;
        }

        if(ans == -1){
            if(big > x)
                ans = 2;
            else if(x % big == 0)
                ans =  x/big;
            else
                ans = x/big + 1;
        }
        cout << ans << "\n";
    }
    
    return 0;   
}
