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

vector<ll> p;

void sieve(ll n){
    
    p.assign(n, -1);

    for(ll i = 2; i < n; i++){
        if(p[i] == -1){
            
            p[i] = i;

            for(ll j = i * i; j < n; j += i){
                p[j] = i;
            }
        }
    }
}

void divide(ll x, ll &x1, ll &x2){

    string s = to_string(x);

    int sz = s.size() / 2;

    string s1 = s.substr(0, sz);
    string s2 = s.substr(sz, s.size() - sz);

    x1 = stoll(s1);
    x2 = stoll(s2);
}

ll solve(ll a, ll b){
    
    if(a > b) return -1;

    ll x1, x2;

    divide(b, x1, x2);

    if(x2 == 0) return solve(a, b - 1);

    ll best = 0;

    ll aux = x1;

    while(p[aux] != -1){
        best = max(best, (x2 / p[aux]) * p[aux]);
        aux /= p[aux];
    }

    if(best == 0) return solve(a, b - x2 - 1);

    return b - x2 + best;
}

int main(){
    optimize;

    sieve(10001000);

    ifstream in("halfnice.in");

    int T;
    in >> T;

    for(int t = 1; t <= T; t++){
        
        ll a, b, x;

        in >> a >> b;

        x = solve(a, b);

        cout << "Case " << t << ": ";

        if(x == -1)
            cout << "impossible" << "\n";
        else
            cout << x << "\n";
    }
    
    return 0;   
}
