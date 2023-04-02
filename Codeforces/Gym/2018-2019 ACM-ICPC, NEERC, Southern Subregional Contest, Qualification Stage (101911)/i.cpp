#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    optimize;

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int maxi = a[0];
    int mini = a[0];

    for(int i = 1; i < n; i++){
        maxi = max(a[i], maxi);
        mini = min(a[i], mini);
    }

    cout << (maxi - mini + 1) - n << "\n";

    return 0;
}