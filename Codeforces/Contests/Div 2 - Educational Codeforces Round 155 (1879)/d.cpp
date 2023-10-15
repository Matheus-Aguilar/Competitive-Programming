#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod 998244353
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 300300

using namespace std;

int n, a[MAXN];

ll calc(int pos){
    
    ll cnt[2] = {0, 0};
    ll pre[2] = {0, 0};
    ll sum = 0;

    for(int i = 0; i < n; i++){
        int x = ((a[i] >> pos) & 1);
        
        if(x == 1){
            swap(cnt[0], cnt[1]);
            swap(pre[0], pre[1]);
        }

        cnt[x] = (cnt[x] + 1) % mod;
        pre[x] = (pre[x] + i) % mod;

        sum = (sum + cnt[1] * (i + 1)) % mod;
        sum = (sum - pre[1] + mod) % mod; 
    }

    return sum;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    ll ans = 0;

    for(int i = 0; i < 30; i++){
        ll val = (1 << i) * calc(i);
        ans = (ans + val) % mod;
    }

    cout << ans << "\n";
    
    return 0;   
}
