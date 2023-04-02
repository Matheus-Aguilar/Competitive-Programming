#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll calc(ll rows, ll cols){
    return rows * (cols % 2);
}

int main() {
    optimize;

    ll n, m, x1, x2, y1, y2;

    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    ll c = calc(n - (x2 - x1 + 1), m);
    c += calc(x2 - x1 + 1, y1 - 1);
    c += calc(x2 - x1 + 1, m - y2);

    cout << (c + 1) / 2 << "\n";

    return 0;
}