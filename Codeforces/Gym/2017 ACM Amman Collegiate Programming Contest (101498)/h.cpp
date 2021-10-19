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
        ll n, s;
        cin >> n >> s;

        if(n % 2 == 0 && s % 2 != 0){
            cout << -1 << "\n";
            continue;
        }

        if(9 * n < s){
            cout << -1 << "\n";
            continue;
        }

        bool ok = true;
        string ans(n, '\0');

        int d = 9;

        for(int i = 0; i < n / 2; i++){
            while(s - 2 * d < 0){
                d--;
            }
            ans[i] = ans[n - i - 1] = (d + '0');
            s -= 2 * d;
        }

        if(n % 2 != 0){
            ans[n / 2] = (s + '0');
        }

        if(ans[0] == '0'){
            cout << -1 << "\n";
            continue;
        }

        cout << ans << "\n";
    }
    
    return 0;   
}