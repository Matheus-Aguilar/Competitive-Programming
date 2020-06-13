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
#define MAXN 500010
#define MAXM 10000010

using namespace std;

pii ans[MAXN];
int prime[MAXM];

void sieve(ll n){
    iota(prime, prime + n + 1, 0);
    for(ll i = 2; i <= n; i++){
        if(prime[i] == i){
            for(ll j = i * i; j <= n; j += i)
                prime[j] = i;
        }
    }
}

int main(){
    optimize;

    sieve(MAXM);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){

        cin >> ans[i].first;
        ans[i].second = prime[ans[i].first];

        while(ans[i].first % ans[i].second == 0)
            ans[i].first /= ans[i].second;
    
        if(ans[i].first == 1)
            ans[i].first = ans[i].second = -1;
    }

    for(int i = 0; i < n; i++)
        cout << ans[i].first << " \n"[i == n - 1];
    for(int i = 0; i < n; i++)
        cout << ans[i].second << " \n"[i == n - 1];

    return 0;   
}
