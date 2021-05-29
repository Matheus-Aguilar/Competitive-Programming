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

    vector<ll> v(n);
    vector<ll> nodes(n + 1, 1);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(all(v));
    reverse(all(v));

    for(int i = 0; i < n; i++)
        nodes[i + 1] = nodes[i] * v[i];

    cout << accumulate(all(nodes), 0LL) << "\n";

    return 0;   
}
