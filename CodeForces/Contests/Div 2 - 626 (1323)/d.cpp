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

//1 se [2^k, 2^(k + 1) - 1] ou [2^(k + 1) + 2^k, 2^(k + 2) - 2]

int main(){
    optimize;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    ll ans = 0;

    for(int i = 0; i <= 26; i++){
        vector<int> module(n);
        for(int j = 0; j < n; j++)
            module[j] = a[j] % (2 << i);
        sort(all(module));
        ll ones = 0;
        for(int j = 0; j < n - 1; j++){
            ones += upper_bound(module.begin() + j + 1, module.end(), (2 << i) - module[j] - 1) - lower_bound(module.begin() + j + 1, module.end(), (1 << i) - module[j]);
            if(i > 0)
                ones += upper_bound(module.begin() + j + 1, module.end(), (4 << i) - module[j] - 2) - lower_bound(module.begin() + j + 1, module.end(), (2 << i) + (1 << i) - module[j]);
        }
        
        ones &= 1;
        ans |= (ones << i);
    }
    cout << ans << "\n";
    
    return 0;   
}
