#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<ll, ll>
#define PI 3.141592653589793238462643383279502884L
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 100100

using namespace std;

//-------------------------- NTT - Paulo Miranda -------------------------------------
const int MOD = 998244353;

inline int modMul(int a, int b) {
  return (int) ((a*(ll)b) % MOD);
}

int base = 1;
vector<ll> roots = {0, 1};
vector<ll> rev = {0, 1};
int max_base = -1;
int root = -1;

inline int power(int a, long long b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) 
        res = modMul(res, a);
        a = modMul(a, a);
        b >>= 1;
    }
    return res;
}
inline int inv(int a) {
    a %= MOD;
    if (a < 0) a += MOD;
    int b = MOD, u = 0, v = 1;
    while(a){
        int t = b / a;
        b -= t * a; swap(a, b);
        u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += MOD;
    return u;
}
void init() {
    int tmp = MOD - 1;
    max_base = 0;
    while (tmp % 2 == 0) {
        tmp /= 2;
        max_base++;
    }
    root = 2;
    while (true) {
        if (power(root, 1 << max_base) == 1) {
        if (power(root, 1 << (max_base - 1)) != 1) {
            break;
        }
        }
        root++;
    }
}
void ensure_base(int nbase) {
    if (max_base == -1)
        init();
    if (nbase <= base)
        return;
    assert(nbase <= max_base);
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++)
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    roots.resize(1 << nbase);
    while (base < nbase) {
        int z = power(root, 1 << (max_base - 1 - base));
        for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        roots[(i << 1) + 1] = modMul(roots[i], z);
        }
        base++;
    }
}
void fft(vector<ll> &a) {
    int n = (int) a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
        if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
        }
    }
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
            int x = a[i + j];
            int y = modMul(a[i + j + k], roots[j + k]);
            a[i + j] = x + y - MOD;
            if (a[i + j] < 0) a[i + j] += MOD;
            a[i + j + k] = x - y + MOD;
            if (a[i + j + k] >= MOD) a[i + j + k] -= MOD;
        }
        }
    }
}
vector<ll> multiply(vector<ll> a, vector<ll> b, int eq = 0) {
    int need = (int) (a.size() + b.size() - 1);
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    fft(a);
    if (eq)
        b = a;
    else
        fft(b);
    int inv_sz = inv(sz);
    for (int i = 0; i < sz; i++)
        a[i] = modMul(modMul(a[i], b[i]), inv_sz);
    reverse(a.begin() + 1, a.end());
    fft(a);
    a.resize(need);
    return a;
}

//-------------- END OF CODE --------------------

const ll mod = 998244353;

ll n;
ll t[MAXN], p[MAXN], fat[MAXN], finv[MAXN], x[MAXN], ans[MAXN];

ll fastExpo(ll x, ll y){
    ll r = 1;
    while(y > 0){
        if(y & 1)
            r = (r * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return r;
}

void precalc(){

    init();

    fat[0] = 1;
    finv[0] = 1;

    for(int i = 1; i < MAXN; i++){
        fat[i] = (i * fat[i - 1]) % mod;
        finv[i] = fastExpo(fat[i], mod - 2);
    }
}

void solve(ll c[], ll k){

    if(k < 0){
        k += mod;
    }

    vector<ll> a(n + 1), b(n + 1);

    for(int i = 0; i <= n; i++){
        a[i] = (c[n - i] * fat[n - i]) % mod;
        b[i] = (fastExpo(k, i) * finv[i]) % mod;
    }

    vector<ll> mult = multiply(a, b);

    for(int i = 0; i <= n; i++){
        x[i] = (mult[n - i] * finv[i]) % mod;
        ans[i] = (ans[i] + x[i]) % mod;
    }
}

int main(){
    optimize;

    precalc();

    ll k;
    cin >> n >> k;

    for(int i = 0; i <= n; i++)
        cin >> t[i];
    
    for(int i = 0; i <= n; i++)
        cin >> p[i];

    solve(t, k);
    solve(p, -k);

    for(int i = 0; i <= n; i++)
        cout << ans[i] << " \n"[i==n];
    
    return 0;   
}
