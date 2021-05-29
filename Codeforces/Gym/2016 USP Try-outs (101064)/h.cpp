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
#define fi first
#define se second

using namespace std;

vector<bool> prime;
vector<int> primes;

pair<vector<int>, int> bruteA[1 << 17];

map<vector<int>, int> ma, mb;

void sieve(int n){

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

vector<int> factors(int val){
    
    vector<int> s;

    for(int i = 0; i < primes.size(); i++){
        while(val % primes[i] == 0){
            s.push_back(primes[i]);
            val /= primes[i];
        }
    }

    if(val != 1) s.push_back(val);

    return s;
}

void mult(vector<int> &a, const vector<int> &b){
    for(int i : b){
        a.push_back(i);
    }
    sort(all(a));
}

void print(const vector<int> &s){
    for(auto i : s){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    optimize;

    sieve(100100);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    vector<vector<int> > va(n), vb(m);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        va[i] = factors(a[i]);
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
        vb[i] = factors(b[i]);
    }
    
    vector<int> sa, sb;

    for(int i = 1; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                mult(sa, va[j]);
            }
        }
        ma[sa] = i;
        sa.clear();
    }

    for(int i = 1; i < (1 << m); i++){
        
        for(int j = 0; j < m; j++){
            if(i & (1 << j)){
                mult(sb, vb[j]);
            }
        }

        if(ma.find(sb) != ma.end()){

            int mask = ma[sb];

            cout << "Y" << "\n";

            cout << __builtin_popcount(mask) << " " << __builtin_popcount(i) << "\n";

            for(int j = 0; j < n; j++){
                if(mask & (1 << j)){
                    cout << a[j] << " ";
                }
            }

            cout << "\n";

            for(int j = 0; j < m; j++){
                if(i & (1 << j)){
                    cout << b[j] << " ";
                }
            }

            cout << "\n";

            return 0;
        }

        sb.clear();
    }

    cout << "N" << "\n";

    return 0;   
}