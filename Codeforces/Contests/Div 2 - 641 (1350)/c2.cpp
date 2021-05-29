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

ll gcd(ll a, ll b){
    return (b ? gcd(b, a % b) : a);
}

ll lcm(ll a, ll b){
    return (a * b)/gcd(a, b);
}

vector<ll> primes;
vector<ll> lp;

void linearSieve(ll n){
    lp.assign(n + 1, 0);
    for(int i = 2; i <= n; i++){
        if(!lp[i]){
            lp[i] = i;
            primes.push_back(i);
        }
        for(int j = 0; j < primes.size() && primes[j] <= lp[i] && i * primes[j] <= n; j++)
            lp[i * primes[j]] = primes[j];
    }
}

int main(){
    optimize;

    linearSieve(200000LL);

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int i = 0;
    ll ans = 1;
    while(i < primes.size()){
        int fail = 0;
        for(int j = 0; j < n; j++){
            if(a[j] % primes[i] != 0){
                fail++;
                if(fail == 2){
                    i++;
                    break;
                }
            }
            else{
                a[j] /= primes[i];
            }
        }
        if(fail <= 1)
            ans *= primes[i];
    }

    cout << ans << "\n";

    return 0;   
}
