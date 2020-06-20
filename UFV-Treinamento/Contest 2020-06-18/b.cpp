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

    ll x = 0, y = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    for(int i = 0; i < n; i++){
        if(i < n/2)
            x += a[i];
        else
            y += a[i];
    }

    cout << x * x + y * y << "\n";

    return 0;   
}
