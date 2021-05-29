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
#define MAXN 100100

using namespace std;

int n, q, a[MAXN], cnt[MAXN], prime[MAXN], go[MAXN], dp[MAXN][20], pot[20];
vector<int> fac[MAXN];

void precalc(){
    
    pot[0] = 1;

    for(int i = 1; i < 20; i++)
        pot[i] = (pot[i - 1] << 1);
}

void sieve(int limit){
    
    ms(prime, 0);

    for(ll i = 2; i < limit; i++){
        if(!prime[i]){
            for(ll j = i * i; j < limit; j += i){
                prime[j] = i;
            }
            prime[i] = i;
        }
    }
}

void getFactors(){
    for(int i = 0; i < n; i++){
        
        int val = a[i];

        while(val > 1){

            int p = prime[val];

            while(val % p == 0)
                val /= p;
        
            fac[i].push_back(p);

        }
    }
}

bool add(int pos){
    
    bool ok = true;
    
    for(int i = 0; i < (int)fac[pos].size(); i++){
        cnt[fac[pos][i]]++;
        ok &= (cnt[fac[pos][i]] <= 1);
    }

    return ok;
}

void rem(int pos){
    for(int i = 0; i < (int)fac[pos].size(); i++)
        cnt[fac[pos][i]]--;
}

void calcGo(){
    
    add(0);
    go[0] = n;

    for(int i = 1; i < n; i++){
        if(!add(i)){
            rem(i);
            go[0] = i;
            break;
        }
    }

    for(int i = 1, j = go[0]; i < n; i++){

        rem(i - 1);

        while(j < n && add(j))
            j++;
        
        if(j < n)
            rem(j);

        go[i] = j;
    }
}

void calcDp(){
    for(int i = n - 1; i >= 0; i--){
        
        dp[i][0] = go[i];

        for(int j = 1; j < 20; j++){
            
            int nxt = dp[i][j - 1];
            
            if(nxt < n)
                dp[i][j] = dp[nxt][j - 1];
            else
                dp[i][j] = n;    
        }
    }
}

int query(int l, int r){
    
    int sum = 0;

    while(l <= r){
        if(go[l] > r){
            sum += 1;
            l = go[l];
        }
        else{
        
            int pos = upper_bound(dp[l], dp[l] + 20, r) - dp[l] - 1;

            sum += pot[pos];
            l = dp[l][pos];
        }
    }

    return sum;
}

int main(){
    optimize;

    sieve(MAXN);
    precalc();
    
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    getFactors();
    calcGo();
    calcDp();

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(l - 1, r - 1) << "\n";
    }

    return 0;   
}
