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
        int n, k, ans = 0;
        cin >> n >> k;

        vector<int> x(n);
        vector<int> y(n);
        
        vector<int> nxt(n);
        vector<int> cover(n + 1, 0);
        vector<int> best(n + 1, 0);

        for(int i = 0; i < n; i++)
            cin >> x[i];
        for(int i = 0; i < n; i++)
            cin >> y[i];
        
        sort(all(x));

        for(int i = 0; i < n; i++)
            nxt[i] = upper_bound(all(x), x[i] + k) - x.begin();

        for(int i = 0; i < n; i++)
            cover[i] = nxt[i] - i;
        
        for(int i = n - 1; i >= 0; i--){
            ans = max(cover[i] + best[nxt[i]], ans);
            best[i] = max(cover[i], best[i + 1]);
        }

        cout << ans << "\n";       
    }

    return 0;   
}
