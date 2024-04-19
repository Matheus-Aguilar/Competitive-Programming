#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

int n, m;
string s;

vector<int> pos[7];
vector<ll> cnt[7];

ll prod = 1, p[7][7];

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

int main(){
    optimize;
    
    cin >> n >> m >> s;

    for(int i = 0; i < s.size(); i++)
        pos[s[i] - 'a'].push_back(-i);

    for(int i = 0; i < n; i++){
        reverse(all(pos[i]));
        cnt[i].assign(pos[i].size(), 0);
    }

    ll q = 1, qprod = 1;

    for(int i = 0; i < n; i++)
        q = (q * pos[i].size()) % mod;

    vector<int> ord(n);
    iota(all(ord), 0);

    char equal = 'S';
    ll last = -1;

    do {
        
        for(int i = 0; i < cnt[ord[n - 1]].size(); i++)
            cnt[ord[n - 1]][i] = 1;

        for(int i = n - 2; i >= 0; i--){
            
            int a = ord[i];
            int b = ord[i + 1];

            for(int j = (int) cnt[b].size() - 2; j >= 0; j--)
                cnt[b][j] += cnt[b][j + 1];
            
            for(int j = 0; j < cnt[a].size(); j++){
                int x = upper_bound(all(pos[b]), pos[a][j]) - pos[b].begin();
                cnt[a][j] = (x == cnt[b].size() ? 0 : cnt[b][x]);
            }
        }

        ll sum = 0;

        for(int i = 0; i < cnt[ord[0]].size(); i++)
            sum = (sum + cnt[ord[0]][i]) % mod;

        for(int i = 0; i < n; i++)
            p[ord[i]][i] = (p[ord[i]][i] + sum) % mod;

        if(last != -1 && last != sum)
            equal = 'N';
        last = sum;

        prod = (prod * sum) % mod;
        qprod = (qprod * q) % mod;

    } while (next_permutation(all(ord)));

    q = fastExpo(q, mod - 2);
    qprod = fastExpo(qprod, mod - 2);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout << (p[i][j] * q) % mod << " \n"[j==n-1];
    
    cout << equal << "\n";
    cout << (prod * qprod) % mod << "\n";

    return 0;   
}
