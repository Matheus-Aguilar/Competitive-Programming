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

vector<pii> v;
vector<ll> x;
vector<ll> y;

struct cmp{
    bool operator()(const int &a, const int &b){
        if(v[a] != v[b]) return v[a] < v[b];
        if(x[a] != x[b]) return x[a] < x[b];
        return y[a] < y[b];
    }
};

set<int, cmp> s;
map<pii, ll> m;

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        
        int n;
        cin >> n;

        v.resize(n);
        x.assign(n, INFLL);
        y.assign(n, INFLL);

        for(int i = 0; i < n; i++){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            v[i] = pii(x1 - x2, y1 - y2);

            if(v[i].second < 0 || (v[i].first < 0 && v[i].second == 0)){
                v[i].first *= -1;
                v[i].second *= -1;
            }

            if(v[i].first != 0 || v[i].second != 0){
                int mdc = __gcd(abs(v[i].first), v[i].second);

                v[i].first /= mdc;
                v[i].second /= mdc;
            }

            x[i] = y1 * v[i].first - x1 * v[i].second;
            y[i] = x1 * v[i].second - y1 * v[i].first;

            auto it = s.insert(i);
        }

        for(int i : s){
            m[v[i]]++;
        }

        ll ans = 0;

        for(int i : s){
            pii p = pii(-v[i].second, v[i].first);

            if(p.second < 0 || (p.first < 0 && p.second == 0)){
                p.first *= -1;
                p.second *= -1;
            }

            ans += m[p];
        }

        cout << ans/2LL << "\n";
    
        v.clear();
        x.clear();
        y.clear();
        m.clear();
        s.clear();
    }

    return 0;   
}