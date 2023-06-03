#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<long long> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        long long sum = 0, gcd = a[0];

        for(int i = 0; i < n; i++){
            sum += a[i];
            gcd = __gcd(gcd, a[i]);
        }

        cout << sum << " " << gcd << "\n";
    }

    return 0;
}