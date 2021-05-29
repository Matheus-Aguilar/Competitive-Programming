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
        int n;
        ll l, r, acu = 0, rem;
        cin >> n >> l >> r;

        int odd = 1, even;
        bool isOdd;

        rem = l;

        for(int i = n - 1; acu + 2 * i < l && i >= 0; i--){
            rem -= 2 * i;
            acu += 2 * i;
            odd++;
        }

        if(odd > n) odd = 1;

        isOdd = rem % 2;
        even = (rem + 1)/2 + odd;

        for(ll i = l; i <= r; i++){
            if(!isOdd){
                cout << even << " ";
                if(even == n){
                    if(odd < n - 1){
                        odd++;
                    }
                    else{
                        odd = 1;
                    }
                    even = odd + 1;
                }
                else{
                    even++;
                }
            }
            else{
                cout << odd << " ";
            }
            isOdd = !isOdd;
        }

        cout << "\n";
    }

    return 0;   
}
