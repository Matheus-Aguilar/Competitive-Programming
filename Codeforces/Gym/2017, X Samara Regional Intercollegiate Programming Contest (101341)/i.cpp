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

int main(){
    optimize;

    mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    
    int n, checks = 10;
    bool ans = true;
    
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(n));
    vector<vector<ll>> b(n, vector<ll>(n));
    vector<vector<ll>> c(n, vector<ll>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> b[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];

    while(checks-- && ans){
        
        vector<ll> x(n);
        vector<ll> cx(n, 0);
        vector<ll> bx(n, 0);
        vector<ll> abx(n, 0);

        for(int i = 0; i < n; i++)
            x[i] = rng() mod;
    
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cx[i] = (cx[i] + (c[i][j] * x[j]) mod) mod;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                bx[i] = (bx[i] + (b[i][j] * x[j]) mod) mod;
    
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                abx[i] = (abx[i] + (a[i][j] * bx[j]) mod) mod;
    
        for(int i = 0; i < n && ans; i++)
            ans &= (abx[i] == cx[i]);
    }

    cout << (ans ? "YES" : "NO") << "\n";

    return 0;   
}
