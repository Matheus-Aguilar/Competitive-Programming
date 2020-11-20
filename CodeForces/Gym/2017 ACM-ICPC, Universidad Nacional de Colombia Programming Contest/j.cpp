#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 30000000
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

const ll p = 30000000;

int main(){
    optimize;

    int n, m, q;
    ll sum = 0;
    cin >> n >> m >> q;
    
    vector<ll> a(n);
    vector<int> c(p, 0);

    for(int i = 0; i < m; i++){
        cin >> a[i];
        c[a[i]]++;
    }
    
    for(int i = m; i < n; i++){
        a[i] = (a[i - m] + a[i - m + 1]) mod;
        c[a[i]]++;
    }

    for(int i = 1; i < p; i++)
        c[i] += c[i - 1];

    while(q--){
        int pos;
        cin >> pos;
        cout << lower_bound(all(c), pos) - c.begin() << "\n";
    }

    return 0;   
}