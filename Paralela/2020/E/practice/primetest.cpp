#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXNUM 100
#define MAXSTR 50
#define MAXRESULTS 1000
#define MAXN 10000000
#define ll long long int 

int ans[MAXRESULTS];
int cont = 0;

vector<bool> prime;
vector<ll> primes;

void sieve(int n){
	
	prime.assign(n + 1, true);

	prime[0] = prime[1] = false;

	for(long long int i = 2; i <= n; i++){
		if(prime[i]){
			for(long long int j = i * i; j <= n; j += i){
				prime[j] = false;		
			}
			primes.push_back(i);
		}
	}
}

int fastExpo(ll x, int y){
	
	ll r = 1;

	while(y > 0){
		if(y & 1)
			r *= x;
		x *= x;
		y >>= 1;
	}

	return r;
}

bool is_prime(ll val){
	
	if(val <= MAXN)
		return prime[val];

	for(int i = 0; i < (int)primes.size() && primes[i] * primes[i] <= val; i++){
		if(val % primes[i] == 0){
			return false;
		}
	}

	return true;
}

int main(int argc,char** argv){ 

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	sieve(MAXN);

	int n;
	cin >> n;

	vector<string> s1(n), s2(n);
	vector<ll> p1(n), p2(n), c(n);
	
	for(int i = 0; i < n; i++){
		cin >> s1[i];
		p1[i] = stoll(s1[i]);
	}
	
	for(int i = 0; i < n; i++){
		cin >> s2[i];
		p2[i] = stoll(s2[i]);
		c[i] = fastExpo(10, s2[i].size());
	}

	#pragma omp paralle for
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			
			ll val = p1[i] * c[j] + p2[j];

			if(is_prime(val)){
				
				int pos;

				#pragma omp atomic capture
				pos = cont++;

				ans[pos] = val;
			}
		}
	}

	sort(ans, ans + cont);

	for(int i = 0; i < cont; i++)
		cout << ans[i] << "\n";

	return 0;
}