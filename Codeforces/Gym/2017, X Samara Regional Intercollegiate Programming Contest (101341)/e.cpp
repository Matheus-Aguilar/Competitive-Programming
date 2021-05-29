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
#define fi first
#define se second

using namespace std;

typedef pair<ll, ll> pll;

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    vector<ll> t(n);
    vector<ll> b(m);
    vector<pll> e(n + m);

    for(int i = 0; i < n; i++){
        cin >> t[i];
        e[i] = pll(t[i], 0);
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
        e[i + n] = pll(b[i], 1);
    }

    sort(all(e));

    ll ans = 0;

    if(e[0].se)
        ans += 2 * abs(t[0] - b[0]);
    if(e[n + m - 1].se)
        ans += 2 * abs(t[n - 1] - b[m - 1]);

    int i = 0;

    while(e[i].se)
        i++;

    while(i < n + m){

        int j = i + 1, k = i + 1;

        while(j < n + m && e[j].se)
            j++;

        if(j >= n + m)
            break;
        
        if(j - i == 1)
            i = j;
        else if(j - i == 2){
            ll best = e[j].fi - e[i].fi;
            
            best = min(best, 2 * (e[k].fi - e[i].fi));
            best = min(best, 2 * (e[j].fi - e[k].fi));

            ans += best;
            i = j;
        }
        else{
            ll best = e[j].fi - e[i].fi;
            
            if(k < j)
                best = min(best, 2 * (e[j].fi - e[k].fi));
            
            while(k < j){
                if(k == j - 1)
                    best = min(best, 2 * (e[k].fi - e[i].fi));
                else
                    best = min(best, 2 * (e[j].fi - e[k + 1].fi + e[k].fi - e[i].fi));
                k++;
            }

            ans += best;
            i = j;
        }
    }

    cout << ans << "\n";

    return 0;   
}
