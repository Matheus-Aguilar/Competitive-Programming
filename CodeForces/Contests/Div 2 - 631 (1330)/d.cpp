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
        ll d, m, i, l;
        vector<ll> a;
        
        cin >> d >> m;

        l = log2(d);
        
        for(i = 0; i < l; i++)
            a.push_back(1LL << i);
        a.push_back(d - (1LL << i) + 1);
        
        for(int i = 0; i < a.size(); i++)
            a[i] %= m;
        
        vector<ll> dp(a.size() + 1, 1LL % m);
        
        for(int i = a.size() - 1; i >= 0; i--)
            dp[i] = (((a[i] + 1LL) % m) * dp[i + 1]) % m;
        cout << (dp[0] - 1 + m) % m << "\n";
    }

    return 0;   
}
