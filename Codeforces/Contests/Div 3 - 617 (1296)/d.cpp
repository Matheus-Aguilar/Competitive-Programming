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

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
        h[i] = (h[i] - 1) % (a + b); //mod
        h[i] = max(0, h[i] - a + 1); //sub
        h[i] = (h[i] + a - 1)/a; //ceil
    }
    sort(all(h));

    int ans = 0;

    for(int i = 0; i < n; i++){
        if(k >= h[i]){
            ans++;
            k -= h[i];
        }
    }

    cout << ans << "\n";

    return 0;   
}
