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
        cin >> x;
        bool ans = false;

        int m[] = {20, 19, 18, 17, 16, 15};
        for(int i = 0; i < 6 && !ans; i++){
            ans = ((x - m[i]) >= 0 && (x - m[i]) % 14 == 0);
        }

        cout << (ans ? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
