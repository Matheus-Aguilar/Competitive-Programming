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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct XorHash{
    
    int n;
    
    vector<int> a; //Array
    vector<int> r; //Random representatives

    vector<int> pa; //Array Prefix xor
    vector<int> pr; //Random prefix xor (permutation prefix xor)

    XorHash(vector<int> &_a, int _n) : a(_a), n(_n){
        
        r.resize(n);
        
        for(int i = 0; i < n; i++)
            r[i] = rng() mod;
        
        pa.assign(n + 1, 0);
        pr.assign(n + 1, 0);

        for(int i = 1; i <= n; i++){
            pa[i] = (pa[i - 1] ^ r[a[i - 1] - 1]);
            pr[i] = (pr[i - 1] ^ r[i - 1]);
        }
    }

    bool query(int a, int b){
        return (pa[b + 1] ^ pa[a]) == pr[b - a + 1];
    }
};

ll solve(vector<int> &a, int n){
    
    XorHash x(a, n);
    
    ll cont = 0;

    int high = -1;
    bool found = false;

    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            found = true;
            high = 1;
            cont++;
        }
        else{
            if(found){

                high = max(high, a[i]);

                if(i - high + 1 >= 0 && x.query(i - high + 1, i))
                    cont++;
            }
        }
    }

    return cont++;
}

int main(){
    optimize;

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;

    ans += solve(a, n);

    reverse(all(a));

    ans += solve(a, n);

    ans -= count_if(all(a), [](int x){ return x == 1; });

    cout << ans << "\n";

    return 0;   
}
