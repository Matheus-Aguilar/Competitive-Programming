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

struct MyHash{
    ll p, m, h = 0;
    int n;
    vector<ll> pot, freq;

    MyHash(ll p, ll m, int n){

        this->p = p;
        this->m = m;
        this->n = n;

        pot.resize(n);
        freq.assign(n, 0);

        pot[0] = p;

        for(int i = 1; i < n; i++)
            pot[i] = (pot[i - 1] * p) % m;
    }

    void add(int x){
        h = (h - (freq[x] * pot[x]) % m + m) % m;
        freq[x]++;
        h = (h + (freq[x] * pot[x]) % m) % m;
    }

    void rem(int x){
        h = (h - (freq[x] * pot[x]) % m + m) % m;
        freq[x]--;
        h = (h + (freq[x] * pot[x]) % m) % m;
    }

    ll getHash(){
        return h;
    }
};

struct PairHash{
    size_t operator()(const pair<ll, ll> &p) const {
        auto hash1 = hash<ll>{}(p.first);
        auto hash2 = hash<ll>{}(p.second);
        if(hash1 == hash2)
            return hash1;
        return (hash1 ^ hash2);
    }
};

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        map<pii, int> id;
        vector<pii> e(n);
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> e[i].first >> e[i].second;
            if(e[i].first > e[i].second)
                swap(e[i].first, e[i].second);
            if(id.find(e[i]) == id.end())
                id[e[i]] = id.size();
            a[i] = id[e[i]];
        }

        MyHash h1(2017, 1000000087, n), h2(2081, 1000000123, n);
        unordered_map<pair<ll, ll>, int, PairHash> cnt;

        for(int i = 0; i < n; i++){
            
            for(int j = i; j < n; j++){
                h1.add(a[j]);
                h2.add(a[j]);
                pair<ll, ll> p = make_pair(h1.getHash(), h2.getHash());
                cnt[p]++;
            }

            for(int j = i; j < n; j++){
                h1.rem(a[j]);
                h2.rem(a[j]);
            }
        }

        ll ans = 0;

        for(auto i : cnt){
            ans += (i.second * (i.second - 1)) / 2;
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
