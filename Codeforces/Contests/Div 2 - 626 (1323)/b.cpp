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
    //optimize;

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n + 1, 0);
    vector<ll> b(m + 1, 0);
    vector<pii> w;
    vector<pii> h;

    int sz = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(!x){
            if(sz){
                a[sz]++;
                sz = 0;
            }
        }
        else{
            sz++;
        }
    }

    if(sz) a[sz]++;
    sz = 0;

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(!x){
            if(sz){
                b[sz]++;
                sz = 0;
            }
        }
        else{
            sz++;
        }
    }

    if(sz) b[sz]++;
    

    for(int i = 1; i <= n; i++)
        if(a[i])
            w.push_back(pii(i, a[i]));
    for(int i = 1; i <= m; i++)
        if(b[i])
            h.push_back(pii(i, b[i]));
    
    
    for(int i = 0; i < w.size(); i++){
        for(int j = 1; j < w[i].first; j++){
            a[j] += w[i].second * (w[i].first - j + 1);
        }
    }
    for(int i = 0; i < h.size(); i++){
        for(int j = 1; j < h[i].first; j++){
            b[j] += h[i].second * (h[i].first - j + 1);
        }
    }

    ll ans = 0;

    for(int i = 1; i <= min(n, k); i++){
        if(k % i == 0 && k/i <= m){
            ans += a[i] * b[k/i];
        }
    }

    cout << ans << "\n";

    return 0;   
}
