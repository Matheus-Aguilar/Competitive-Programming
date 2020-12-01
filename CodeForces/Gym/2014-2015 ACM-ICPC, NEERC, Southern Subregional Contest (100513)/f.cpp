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

    int n, k, ans = 0;
    cin >> n >> k;

    vector<int> f(n);

    for(int i = 0; i < n; i++)
        cin >> f[i];
    
    while(n < 2 * k){
        f.push_back(0);
        n++;
    }

    vector<int> best(n, 0);

    int window = 0;

    for(int i = n - 1; i >= n - k; i--)
        window += f[i];
    
    best[n - k] = window;

    for(int i = n - k - 1; i >= 0; i--){
        window -= f[i + k];
        window += f[i];
        best[i] = max(window, best[i + 1]);
    }

    window = 0;

    for(int i = 0; i < k; i++)
        window += f[i];
    
    ans = window + best[k];

    for(int i = k; i < n - 1; i++){
        window -= f[i - k];
        window += f[i];
        ans = max(ans, window + best[i + 1]);
    }

    cout << ans << "\n";

    return 0;   
}
