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

    long double c, l, d, f;

    cin >> c >> l >> d >> f;

    int n;

    cin >> n;

    ll inside = c * l * d;
    ll outside = (2 * c + 2 * l) * f;

    inside = max(inside, 1LL);
    outside = max(outside, 1LL);

    cout << (inside + outside >= n ? "YES" : "NO") << "\n"; 
    
    return 0;   
}
