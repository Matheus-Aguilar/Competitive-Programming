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

    int l, r, n;
    cin >> n >> l >> r;

    int minimal = 0, maximal = 0;

    minimal += (1 << l) - 1;
    minimal += n - l;

    maximal += (1 << r) - 1;
    maximal += (n - r) * (1 << (r - 1));

    cout << minimal << " " << maximal << "\n";

    return 0;   
}
