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

int n, k, m, multiple = 0;
const ll prime = 1000000007;

void print(vector<ll> &a){
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " \n"[i==a.size()-1];
}

vector<ll> mult(vector<ll> &a, vector<ll> &b){
    
    vector<ll> c(a.size(), 0LL);

    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            c[(i + j) % m] = (c[(i + j) % m] + (a[i] * b[j]) mod) mod;

    return c;
}

vector<ll> solve(vector<ll> x, int y){
    
    vector<ll> r(x.size(), 0LL);

    r[0] = 1;

    while(y > 0){
        if(y & 1)
            r = mult(r, x);
        x = mult(x, x);
        y >>= 1;
    }

    return r;
}

ll fastExpo(ll x, ll y){
    
    ll r = 1LL;

    while(y > 0){
        if(y & 1)
            r = (r * x) mod;
        x = (x * x) mod;
        y >>= 1;
    }

    return r;
}


int main(){
    optimize;


    cin >> n >> k >> m;

    vector<ll> cont(m, 0);

    for(int i = 1; i <= k; i++){
        if(i % m != 0)
            cont[i % m]++;
        else
            multiple++;
    }

    vector<ll> ans = solve(cont, n);

    ll p = ans[0], q = fastExpo(k - multiple, n);

    cout << (p * fastExpo(q, prime - 2)) mod << "\n";

    return 0;   
}
