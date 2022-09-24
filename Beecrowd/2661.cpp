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

vector<bool> prime;
vector<ll> primos;

void crivo(ll n){
    prime.assign(n + 1, true);
    prime[0] = prime[1] = false;
    for(ll i = 2; i <= n; i++){
        if(prime[i]){
            for(ll j = i * i; j <= n; j += i){
                prime[j] = false;
            }
            primos.push_back(i);
        }
    }
}

int main(){
    optimize;
    
    crivo(1000000);

    ll n, divisors = 0;
    cin >> n;

    for(int i = 0; i < primos.size() && primos[i] <= n; i++){
        if(n % primos[i] == 0){
            divisors++;
            while(n % primos[i] == 0){
                n /= primos[i];
            }
        }
    }

    if(n != 1) divisors++;

    cout << (1LL << divisors) - (divisors + 1) << "\n";

    return 0;   
}
