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

int n, odd = 0, even = 1, cnt = 0;
ll ans = 0;

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        cnt += x;

        if(cnt % 2 == 0){
            even++;
            ans += odd;
        } else {
            odd++;
            ans += even;
        }
    }

    cout << ans << "\n";
    
    return 0;   
}
