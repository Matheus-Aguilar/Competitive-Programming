#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 200100

using namespace std;

int n, a[MAXN], cnt[MAXN], maxi = 0;

int main() {
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);

    int rep = a[0];

    for(int i = 0; i < n; i++){
        
        if(a[i] % rep != 0){
            cout << -1 << "\n";
            return 0;
        }
        
        a[i] /= rep;
    
        if(__builtin_popcount(a[i]) != 1){
            cout << -1 << "\n";
            return 0;
        }

        int pos = __builtin_ctz(a[i]);
        cnt[pos]++;
        maxi = max(maxi, pos);
    }

    int ans = 0, i = 0;

    while(n > 1){
        
        ans += cnt[i] % 2;
        cnt[i + 1] += (cnt[i] + 1) / 2;

        n -= cnt[i];
        n += (cnt[i] + 1) / 2;

        i++;
    }

    cout << ans << "\n";

    return 0;
}