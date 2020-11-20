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

const long double eps = 1e-6;

int main() {
    
    optimize;

    ll n, m, q, g1, g2;
    cin >> n >> m >> q;
    
    g1 = n/__gcd(n, m);
    g2 = m/__gcd(n, m);
    
    while(q--){
        ll a1, s1, a2, s2, l1, l2, r1,r2;
        cin >> a1 >> s1 >> a2 >> s2;
        
        s1--, s2--;
        
        if(a1 == 1){
            l1 = s1 - s1 % g1;
            r1 = s1 + g1 - s1 % g1;
        }
        else{
            l1 = s1 - s1 % g2;
            r1 = s1 + g2 - s1 % g2;
            l1 = (l1/g2) * g1;
            r1 = (r1/g2) * g1;
        }
        
        if(a2 == 1){
            l2 = s2 - s2 % g1;
            r2 = s2 + g1 - s2 % g1;
        }
        else{
            l2 = s2 - s2 % g2;
            r2 = s2 + g2 - s2 % g2;
            l2 = (l2/g2) * g1;
            r2 = (r2/g2) * g1;
        }
        
        cout << (l1 == l2 && r1 == r2 ? "SIM" : "NAO") << "\n";
    }
    
    return 0;
}
