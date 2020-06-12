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

    string s;
    cin >> s;

    ll ans = 0;

    for(int i = 0; i < s.size(); i++)
        if(s[i] == '0' || s[i] == '4' || s[i] == '8')
            ans++;

    for(int i = 0; i < s.size() - 1; i++){
        int a = (int)(s[i] - '0');
        int b = (int)(s[i + 1] - '0');
        if((10 * a + b) % 4 == 0){
            ans += i + 1;
        }
    }

    cout << ans << "\n";
    
    return 0;   
}
