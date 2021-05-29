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

    vector<ll> a(n), b(n), c(n), d(n);

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    long double l = 0, r = INFLL, m, sum;

    for(int k = 0; k < 150; k++){

        m = l + (r - l)/2.0;
        
        sum = 0.0;

        for(int i = 0; i < n; i++){
            if(b[i] - a[i] * m > d[i] - c[i] * m)
                sum += b[i] - a[i] * m;
            else
                sum += d[i] - c[i] * m;
        }

        if(sum >= 0)
            l = m;
        else
            r = m;
    }

    cout << fixed << setprecision(15) << m << "\n";

    return 0;   
}
