#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 1000100

using namespace std;

const ll mod = 1000000007;
ll fat[MAXN];

void precalc(){
    fat[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fat[i] = (i * fat[i - 1]) % mod;
}

int n, q, a[MAXN];
unordered_map<int, int> cnt;

ll num = 1LL, dem = 1LL;

ll fastExpo(ll x, int y){
    ll r = 1LL;
    while(y > 0){
        if(y & 1)
            r = (r * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return r;
}

int main(){

    optimize;

    precalc();

    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    dem = fat[n];

    for(auto x : cnt){
        num = (num * fat[x.second]) % mod;
    }

    cout << (num * fastExpo(dem, mod - 2)) % mod << "\n";

    while(q--){
        int pos, x;
        cin >> pos >> x;

        pos--;

        if(a[pos] != x){
            int f1 = cnt[a[pos]];
            int f2 = cnt[x];

            dem = (dem * fat[f1]) % mod;
            dem = (dem * fat[f2]) % mod;
            num = (num * fat[f1 - 1]) % mod;
            num = (num * fat[f2 + 1]) % mod;

            cnt[a[pos]]--;
            cnt[x]++;

            a[pos] = x;
        }

        cout << (num * fastExpo(dem, mod - 2)) % mod << "\n";
    }

    return 0;
}