#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 200200

using namespace std;

int n, h, x1[MAXN], x2[MAXN], a[MAXN];

int main() {
    optimize;

    cin >> n >> h;

    for(int i = 0; i < n; i++)
        cin >> x1[i] >> x2[i];

    for(int i = 1; i < n; i++){
        a[i] = x1[i] - x2[i - 1];
    }

    for(int i = 1; i < n; i++){
        a[i] += a[i - 1];
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        int pos = lower_bound(a, a + n, a[i] + h) - a - 1;
        ans = max(ans, (x2[pos] + h + a[i] - a[pos]) - x1[i]);
    }

    cout << ans << "\n";

    return 0;
}