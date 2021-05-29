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

int mdc(int a, int b){
    return (b ? mdc(b, a % b) : a);
}

int mmc(int a, int b){
    return (a * b)/mdc(a, b);
}

int calc(int a, int b, ll x){
    return ((x % a) % b) != ((x % b) % a);
}

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int a, b, q;
        cin >> a >> b >> q;

        ll cycleSize = mmc(a, b);
        vector<ll> cyclePrefix(cycleSize, 0);

        for(int i = 1; i < cycleSize; i++){
            cyclePrefix[i] = cyclePrefix[i - 1] + calc(a, b, i);
        }

        while(q--){
            ll l, r, ans = 0;
            cin >> l >> r;

            if(r - l + 1 <= cycleSize){
                if(l % cycleSize > r % cycleSize){
                    ans += cyclePrefix.back() - cyclePrefix[l % cycleSize] + calc(a, b, l);
                    ans += cyclePrefix[r % cycleSize]; 
                }
                else{
                    ans += cyclePrefix[r % cycleSize] - cyclePrefix[l % cycleSize] + calc(a, b, l);
                }
            }
            else{
                ans += cyclePrefix.back() - cyclePrefix[l % cycleSize] + calc(a, b, l);
                ans += cyclePrefix[r % cycleSize];

                l += (cycleSize - l % cycleSize);
                r -= r % cycleSize;

                ans += cyclePrefix.back() * ((r - l)/cycleSize);
            }

            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;   
}
