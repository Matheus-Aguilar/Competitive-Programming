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

    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> rev(n);

    vector<ll> p(n + 1, 0);

    vector<ll> ar(n);
    vector<ll> pr(n + 1, 0);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++)
        cin >> b[i];

    rev = a;
    reverse(all(rev));

    for(int i = 1; i <= n; i++){
        p[i] = p[i - 1] + a[i - 1] * b[i - 1];
    }

    ll best = p[n]; //without reverse

    for(int i = 0; i < 2 * n - 1; i++){
        
        fill(all(ar), 0);

        for(int j = 0; j < n; j++){
            
            int k = j + i - n + 1;
            
            if(k >= 0 && k < n)
                ar[k] = rev[j];
        }

        for(int j = 1; j <= n; j++){
            pr[j] = pr[j - 1] + ar[j - 1] * b[j - 1];
        }

        for(int l = 1; l <= n; l++){
        
            int r = i - l + 2;

            if(r < l || r > n)
                continue;

            best = max(best, p[l - 1] + (p[n] - p[r]) + (pr[r] - pr[l - 1]));
        }
    }

    cout << best << "\n";
    
    return 0;   
}
