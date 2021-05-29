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
        int n, x, l = INF, r = -1;
        cin >> n >> x;
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] % x){
                l = min(l, i);
                r = max(r, i);
            }
        }

        if(accumulate(all(a), 0) % x)
            cout << n << "\n";
        else if(l == INF)
            cout << r << "\n";
        else
            cout << max(n - l - 1, r) << "\n";
    }
    
    return 0;   
}
