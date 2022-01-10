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
    
    int n, l, p;

    while(cin >> n >> l >> p){
        int best = INF, ans = -1;

        for(int i = p; i > 0; i--){
            int r = n % i;
            int a = (n - r) / i;

            if(r < best && a <= l){
                best = r;
                ans = a;
            }
        }

        if(ans == -1){
            ans = l;
            best = max(0, n - l * p); 
        }

        cout << ans << " " << best << "\n";
    }

    return 0;   
}
