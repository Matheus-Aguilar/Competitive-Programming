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

    int n, m;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    reverse(all(a));

    cin >> m;
    vector<int> q(m);
    for(int i = 0; i < m; i++)
        cin >> q[i];

    ll sum = accumulate(all(a), 0LL);

    for(int i = 0; i < m; i++)
        cout << sum - a[q[i] - 1]<< "\n";
    
    return 0;   
}
