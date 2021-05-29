#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<ll, ll>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

vector<ll> primes;
vector<ll> prime;

void sieve(ll n){

    prime.assign(n + 1, 1);

    for(ll i = 2; i <= n; i++){
        if(prime[i] == 1){
            for(ll j = i * i; j <= n; j += i){
                prime[j] = i;
            }
            prime[i] = i;
            if(i <= 500) primes.push_back(i);
        }
    }
}

int main(){
    
    optimize;

    sieve(51000);

    ll T;
    cin >> T;

    cout << primes.size() << "\n";

    for(ll t = 1; t <= T; t++){

        ll m;
        cin >> m;

        vector<ll> p(m), n(m);
        vector<ll> c(100, 0LL), cont(100, 0LL);

        for(ll i = 0; i < m; i++){
            
            cin >> p[i] >> n[i];
            
            ll pos = lower_bound(all(primes), p[i]) - primes.begin();

            c[pos] += n[i];
        }

        ll ans = 0;

        for(ll i = 500LL * 100LL; i > 0LL; i--){
            
            ll val = i, sum = 0;
            bool ok = true;

            fill(all(cont), 0LL);
            
            while(val > 1LL && ok){
                
                ll fac = prime[val];
                ll pos = lower_bound(all(primes), fac) - primes.begin();

                if(pos >= primes.size()){
                    ok = false;
                    continue;
                }

                while(val % fac == 0LL){
                    cont[pos]++;
                    val /= fac;
                }
            }

            for(ll j = 0LL; j < cont.size() && ok; j++){
                if(cont[j] > c[j])
                    ok = false;
                else
                    sum += primes[j] * (c[j] - cont[j]);
            }

            if(!ok) continue;

            if(sum == i){
                ans = i;
                break;
            }
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
    
    return 0;   
}
