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
#define MAXN 300300

using namespace std;

int n, h[MAXN];
string str;

struct Hash {

    int N;
    ll P, M;
    vector<ll> h, p;

    Hash(const string &s, ll _P, ll _M) : P(_P), M(_M) {
        
        N = s.size();
        
        h.resize(N + 1);
        p.resize(N + 1);

        p[0] = 1;

        for(int i = 1; i <= N; i++)
            p[i] = (p[i - 1] * P) % M;
        
        h[0] = 0;

        for(int i = 1; i <= N; i++){
            int c = s[i - 1] - 'A' + 1;
            h[i] = (h[i - 1] + (c * p[i]) % M) % M;
        }
    }

    ll getHash(int l, int r){
        ll diff = (h[r] - h[l - 1] + M) % M; 
        return (diff * p[N - l]) % M;
    }
};

string solve(int k, Hash &H) {
    
    for(int i = 0; i < n - k + 1; i++){
        h[i] = H.getHash(i + 1, i + k);
    }

    sort(h, h + n - k + 1);

    for(int i = 0; i < n - k + 1; i++){
        ll c = H.getHash(i + 1, i + k);

        if(upper_bound(h, h + n - k + 1, c) - lower_bound(h, h + n - k + 1, c) == 1){
            return str.substr(i, k);
        }
    }

    return "";
}

bool check(int k, Hash &H) {
    
    for(int i = 0; i < n - k + 1; i++){
        h[i] = H.getHash(i + 1, i + k);
    }

    sort(h, h + n - k + 1);

    for(int i = 0; i < n - k + 1; i++){
        bool ok = true;
        if(i > 0 && h[i] == h[i - 1])
            ok = false;
        if(i < n - k && h[i] == h[i + 1])
            ok = false;
        if(ok) 
            return true;
    }

    return false;
}

int binSearch(int l, int r, Hash &H){
    while(l < r){
        int m = l + (r - l) / 2;

        if(check(m, H))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    optimize;

    cin >> str;

    n = str.size();

    Hash H(str, 41, 2153732767);
    //Hash h(str, 37, 1479251503);

    int sz = binSearch(1, n, H);

    cout << solve(sz, H) << "\n";
    
    return 0;   
}
