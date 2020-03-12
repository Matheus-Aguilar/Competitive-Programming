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
        int n;
        ll k;
        
        cin >> n >> k;
        
        vector<ll> a(n);
        set<ll> ki;
        bool ok = true;

        for(int i = 0; i < n; i++) 
            cin >> a[i];

        if(k != 1){
            ki.insert(-1);
            for(ll i = k; i <= 10000000000000000LL; i *= k)
                ki.insert(-i);
            for(int i = 0; i < n; i++){
                vector<ll> used;
                auto it = ki.begin();
                while(it != ki.end() && a[i]){
                    ll val = -(*it);
                    if(val <= a[i]){
                        a[i] -= val;
                        used.push_back(-val);
                    }
                    it++;
                }

                if(a[i]){
                    ok = false;
                    break;
                }
                else{
                    for(ll i:used){
                        ki.erase(i);
                    }
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;   
}
