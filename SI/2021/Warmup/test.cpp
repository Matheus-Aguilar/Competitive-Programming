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
#define MAXN 200000000

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<long long, int, custom_hash> safe_map;

ll v[MAXN];

ordered_set s;

ll solve(ll n){
    if(n <= 0)
        return 1LL;
    return n * solve(n - 2);
}

ll solve2(ll i, ll n){
    if(i == n)
        return i;
    return solve2(i + 1, n) * i;
}

int main(){
    optimize;

    ll n;

    cin >> n;
    //cout << solve(n) << "\n";
    
    // s.insert(20);
    // s.insert(10);
    // s.insert(30);

    // cout << s.order_of_key(20) << " " << *s.find_by_order(1) << "\n";

    vector<vector<ll>> v(n, vector<ll>(n, solve(n)));

    cout << v[n-1][n-1] << "\n";

    safe_map[1000101] = 1;
    cout << safe_map.size() << "\n";

    return 0;   
}
