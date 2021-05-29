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

    int n;
    ll t, ans = 0;

    cin >> n;

    deque<ll> d;

    for(int i = 0; i < n; i++){
        cin >> t;
        d.push_back(t);
    }

    sort(all(d));

    while(!d.empty()){

        int sz = d.size();

        if(sz == 1){
            ans += d.front();
            d.pop_front();
        }
        else if(sz == 2){
            ans += d.back();
            d.pop_back();
            d.pop_back();
        }
        else if(sz == 3){
            ll a1 = d[0], a2 = d[1], b1 = d[sz - 1];
            ans += (a1 + a2 + b1);
            d.pop_back();
            d.pop_back();
            d.pop_back();
        }
        else{
            ll a1 = d[0], a2 = d[1], b1 = d[sz - 2], b2 = d[sz - 1];
            ans += min(2 * a1 + b1 + b2, a1 + 2 * a2 + b2);
            d.pop_back();
            d.pop_back();
        }

        //cout << ans << "\n";
    }

    cout << ans << "\n";
    
    return 0;   
}
