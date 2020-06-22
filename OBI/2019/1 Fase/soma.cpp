#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<long long int, long long int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

ll sumN(ll n){
    return (n * (n + 1))/2;
}

int main(){
    optimize;

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<pii> b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] != 0){
            b.push_back(pii(a[i], i));
        }
    }

    ll ans = 0LL;
    
    if(k == 0 && b.empty()){
        ans = sumN(n);
    }
    else if(b.empty()){
        ans = 0LL;
    }
    else if(k == 0){
        ans += sumN(b[0].second);
        for(int i = 1; i < b.size(); i++)
            ans += sumN(b[i].second - b[i - 1].second - 1);
        ans += sumN(n - b.back().second - 1);
    }
    else{
        int l = 0, r = 0, sum = b[0].first;
        while(r < (int)b.size()){
            if(sum < k || l > r){
                r++;
                sum += b[r].first;
            }
            else if(sum > k){
                sum -= b[l].first;
                l++;
            }
            else{
                ll prefix, suffix;
                if(l == 0)
                    prefix = b[l].second + 1;
                else
                    prefix = b[l].second - b[l - 1].second;
                if(r + 1 == b.size())
                    suffix = n - b[r].second;
                else
                    suffix = b[r + 1].second - b[r].second;
                ans += prefix * suffix;

                r++;
                sum += b[r].first - b[l].first;
                l++;
            }
        }
    }
    cout << ans << "\n";

    
    return 0;   
}
