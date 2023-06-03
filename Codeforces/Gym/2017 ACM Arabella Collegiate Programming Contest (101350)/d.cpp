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

        vector<int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        sort(a.begin(), a.end());

        bool ok = true;

        for(int i = 1; i < n; i++){
            if((a[i] - a[i - 1]) % 2 != 0){
                ok = false;
                break;
            }
        }

        cout << (ok ? "yes" : "no") << "\n";
    }

    return 0;
}