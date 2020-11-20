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

ll f[12] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

int main(){
    optimize;

    //10 7 6

    ll n, a, b;
    cin >> n >> a >> b;

    if(n == 0) n++;
    if(a == 0) a++;
    if(b == 0) b++;
    
    if(a == 1 && n == b){
        cout << "YES" << "\n";
        return 0;
    }

    if(b == 1 && n == a){
        cout << "YES" << "\n";
        return 0;
    }

    if(a > n || b > n){
        cout << "NO" << "\n";
        return 0;
    }

    if(n >= a + b){
        cout << "NO" << "\n";
        return 0;
    }

    if(a < b) swap(a, b);

    if(b > 13){
        cout << "NO" << "\n";
        return 0;
    }    

    ll p1 = 1, p2 = 1;

    for(int i = 1; i <= b; i++)
        p2 = p2 * i;
    
    for(ll i = n; p1 <= p2 && i > a; i--)
        p1 = p1 * i;

    cout << (p1 == p2 ? "YES" : "NO") << "\n";

    return 0;   
}
