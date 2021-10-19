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

void sieve(int n){
    prime.assign(n, true);
    prime[0] = prime[1] = false;

    for(ll i = 0; i < n; i++){
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

    sieve(1000100);

    int x, cont = 0, i = primes.size();
    cin >> x;

    while(x >= 4){
        while(primes[i] > x || !prime[x - primes[i]]){
            i--;
        }
        x = primes[i] - (x - primes[i]);
        cont++;
    }

    cout << cont << "\n";
    
    return 0;   
}
