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

    int n, x, y, ans = 0, half, total;
    cin >> n >> x >> y;
    
    half = (1 << (n - 1));
    total = (1 << n);

    while(x != half){
        if(x < half)
            x = 2 * x;
        else
            x = 2 * x - total;
        ans++;
    }

    cout << ans << "\n";

    return 0;   
}
