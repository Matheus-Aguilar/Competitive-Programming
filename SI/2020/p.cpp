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

    ll c, a, p, val;

    cin >> c >> a >> p;

    vector<int> cont(p);

    val = 4 * c * a;

    cont[0] = val;

    for(int i = 1; i < p; i++)
        cont[i] = (cont[i - 1] * val) mod;

    ll sum = 0;

    for(int i = 0; i < p; i++)
        sum = (sum + cont[i]) mod;

    cout << sum << "\n";

    return 0;   
}
