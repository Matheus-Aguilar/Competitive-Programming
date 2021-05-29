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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> minimum(n/2);
        vector<int> maximum(n/2);
        vector<int> sum(n/2);

        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n/2; i++){
            minimum[i] = min(a[i], a[n - i - 1]) + 1;
            maximum[i] = max(a[i], a[n -i - 1]) + k;
            sum[i] = a[i] + a[n - i - 1];
        }

        sort(all(minimum));
        sort(all(maximum));
        sort(all(sum));

        int ans = INF;

        for(int i = 2; i <= 2 * k; i++){
            int bigger = minimum.end() - upper_bound(all(minimum), i);
            int smaller = lower_bound(all(maximum), i) - maximum.begin();
            int equal = upper_bound(all(sum), i) - lower_bound(all(sum), i);
            ans = min(ans, 2 * (bigger + smaller) + (n/2 - (bigger + smaller + equal)));
        }

        cout << ans << "\n";
    }

    return 0;   
}
