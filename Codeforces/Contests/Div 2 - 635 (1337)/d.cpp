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

ll calc(ll x, ll y, ll z){
    return (x - y) * (x - y) + (y - z) * (y - z) + (x - z) * (x - z);
}

ll solve(vector<ll> &menor, vector<ll> &meio, vector<ll> &maior){
    int i = 0, j = 0, k = 0;
    
    while(j < meio.size() && menor[i] > meio[j]) j++;
    if(j >= meio.size()) return INFLL;

    while(k < maior.size() && meio[j] > maior[k]) k++;
    if(k >= maior.size()) return INFLL;

    ll ans = INFLL;

    while(k < maior.size()){
        ans = min(ans, calc(menor[i], meio[j], maior[k]));
        if(i + 1 < menor.size() && menor[i + 1] <= meio[j])
            i++;
        else if(j + 1 < meio.size() && meio[j + 1] <= maior[k])
            j++;
        else
            k++;
    }

    return ans;
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        int nr, ng, nb;
        cin >> nr >> ng >> nb;

        vector<ll> r(nr);
        vector<ll> g(ng);
        vector<ll> b(nb);

        ll ans = INFLL;

        for(int i = 0; i < nr; i++) cin >> r[i];
        for(int i = 0; i < ng; i++) cin >> g[i];
        for(int i = 0; i < nb; i++) cin >> b[i];
    
        sort(all(r));
        sort(all(g));
        sort(all(b));

        ans = min(ans, solve(r, g, b));
        ans = min(ans, solve(r, b, g));
        ans = min(ans, solve(g, r, b));
        ans = min(ans, solve(g, b, r));
        ans = min(ans, solve(b, r, g));
        ans = min(ans, solve(b, g, r));

        cout << ans << "\n";
    }
    
    return 0;   
}
