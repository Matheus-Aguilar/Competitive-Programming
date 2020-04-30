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

ll calc(ll a, ll b, ll c){
    return abs(a - b) + abs(a - c) + abs(b - c);
}

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int m[3] = {-1, 0, 1};
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = INFLL;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 3; k++)
                    ans = min(ans, calc(a + m[i], b + m[j], c + m[k]));
        cout << ans << "\n";
    }

    return 0;   
}
