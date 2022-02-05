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

int n, a[MAXN], q, cont[MAXN][101];

ll fastExpo(ll x, int y, ll m){
    ll r = 1LL;
    while(y > 0) {
        if(y & 1) r = (r * x) % m;
        y >>= 1;
        x = (x * x) % m;
    }
    return r;
}

bool prime[120];
int primes[120], pn;

int fac[120][10], fn[120];

int main(){
    //optimize;
    
    for(int i = 1; i <= 100; i++){
        
        int num = i;
        
        while(num % 2 == 0){
            fac[i][fn[i]++] = 2;
            num /= 2;
        }
        while(num % 3 == 0){
            fac[i][fn[i]++] = 3;
            num /= 3;
        }
        while(num % 5 == 0){
            fac[i][fn[i]++] = 5;
            num /= 5;
        }
        while(num % 7 == 0){
            fac[i][fn[i]++] = 7;
            num /= 7;
        }

        if(num != 1){
            fac[i][fn[i]++] = num;
        }
    }

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 100; j++){
            cont[i][j] = cont[i - 1][j];
        }
        for(int j = 0; j < fn[a[i]]; j++){
            cont[i][fac[a[i]][j]]++;
        }
    }

    scanf("%d", &q);

    while(q--){

        int l, r;
        ll m, p = 1LL;

        scanf("%d%d%Ld", &l, &r, &m);

        for(int i = 1; i <= 100; i++){
            int c = cont[r][i] - cont[l-1][i];
            
            ll e = fastExpo(i, c, m);
            p = (p * e) % m;
        }

        printf("%Ld\n", p);
    }

    return 0;   
}
