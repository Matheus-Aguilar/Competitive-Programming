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
vector<int> primes;

void sieve(ll n){
    prime.assign(n, true);

    for(ll i = 2; i < n; i++){
        if(prime[i]){
            for(ll j = i * i; j < n; j += i){
                prime[j] = false;
            }
            primes.push_back(i);
        }
    }
}

int main(){
    optimize;

    sieve(1000000);

    int t;
    cin >> t;

    while(t--){
        int d, p1, p2;
        cin >> d;

        p1 = *lower_bound(all(primes), 1 + d);
        p2 = *lower_bound(all(primes), p1 + d);

        cout << p1 * p2 << "\n";
    }
    
    return 0;   
}
