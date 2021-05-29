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
#define MAXN 10000010

using namespace std;

vector<bool> prime;
vector<ll> primes;

void sieve(){
    prime.assign(MAXN, true);
    
    prime[0] = prime[1] = false;

    for(ll i = 2; i < MAXN; i++){
        if(prime[i]){
            for(ll j = i * i; j < MAXN; j += i){
                prime[j] = false;
            }
            primes.push_back(i);
        }
    }
}

int main(){
    optimize;

    sieve();

    ll a, b, g, ans = 1LL;

    cin >> a >> b;

    g = __gcd(a, b);

    a /= g;
    b /= g;

    for(ll i = 0; i < primes.size() && primes[i] <= b; i++){
        
        if(b % primes[i] == 0){
            
            ans *= primes[i];

            while(b % primes[i] == 0){
                b /= primes[i];
            }
        }
    }

    long double root = sqrtl(b);

    if(root == (int) root)
        ans *= root;
    else
        ans *= b;

    ans = max(ans, 2LL);

    cout << ans << "\n";
    
    return 0;   
}
